#!/usr/bin/env python3
"""Rank Daily_Leetcode problems by review priority from Markdown practice logs."""

from __future__ import annotations

import argparse
import json
import re
from dataclasses import dataclass, asdict
from datetime import date, datetime
from pathlib import Path
from typing import Any

RESULT_WEIGHT = {
    "参考答案后做对": 55,
    "修改后做对": 35,
    "一次性做对": 8,
}
MASTERY_WEIGHT = {
    "Beginner": 25,
    "Familiar": 14,
    "Proficient": 0,
}
CORE_LABELS = {
    "Array",
    "Hash Table",
    "Two Pointers",
    "Binary Search",
    "Sliding Window",
    "Linked List",
    "Tree",
    "Graph",
    "BFS",
    "DFS",
    "Backtracking",
    "Stack",
    "Queue",
    "Heap",
    "Dynamic Programming",
}


@dataclass
class PracticeEntry:
    date: str = ""
    duration: str = ""
    result: str = ""
    notes: str = ""
    minutes: int | None = None
    days_ago: int | None = None


@dataclass
class ProblemRank:
    score: float
    path: str
    title: str
    labels: list[str]
    attempts: str
    status: str
    link: str
    latest: PracticeEntry | None
    entry_count: int
    reasons: list[str]


def section(text: str, heading: str) -> str:
    pattern = re.compile(rf"^## {re.escape(heading)}\n(?P<body>.*?)(?=^## |\Z)", re.M | re.S)
    match = pattern.search(text)
    return match.group("body").strip("\n") if match else ""


def parse_title(text: str) -> str:
    match = re.search(r"^#\s+(.+)$", text, re.M)
    return match.group(1).strip() if match else "Untitled"


def parse_labels(text: str) -> list[str]:
    body = section(text, "Labels")
    labels = []
    for line in body.splitlines():
        line = line.strip()
        if line.startswith("- "):
            labels.append(line[2:].strip())
    return labels


def parse_mastery(text: str) -> tuple[str, str]:
    body = section(text, "Mastery")
    attempts = ""
    status = ""
    for line in body.splitlines():
        stripped = line.strip()
        if stripped.startswith("- Attempts:"):
            attempts = stripped.split(":", 1)[1].strip()
        elif stripped.startswith("- Status:"):
            status = stripped.split(":", 1)[1].strip()
    return attempts, status


def parse_link(text: str) -> str:
    body = section(text, "Link")
    for line in body.splitlines():
        stripped = line.strip()
        if stripped.startswith("http"):
            return stripped
    return ""


def parse_minutes(raw: str) -> int | None:
    text = raw.strip().lower()
    if not text:
        return None
    hour_match = re.search(r"(\d+(?:\.\d+)?)\s*(h|hr|hour|hours|小时)", text)
    minute_match = re.search(r"(\d+)\s*(m|min|mins|minute|minutes|分钟)", text)
    total = 0.0
    if hour_match:
        total += float(hour_match.group(1)) * 60
    if minute_match:
        total += int(minute_match.group(1))
    if total:
        return int(round(total))
    only_number = re.fullmatch(r"\d+", text)
    if only_number:
        return int(text)
    return None


def parse_days_ago(raw: str, today: date) -> int | None:
    value = raw.strip()
    if not value:
        return None
    try:
        return (today - date.fromisoformat(value)).days
    except ValueError:
        pass
    for fmt in ("%Y/%m/%d", "%m/%d/%Y", "%m/%d"):
        try:
            parsed = datetime.strptime(value, fmt).date()
            if fmt == "%m/%d":
                parsed = parsed.replace(year=today.year)
            return (today - parsed).days
        except ValueError:
            continue
    return None


def parse_practice_log(text: str, today: date) -> list[PracticeEntry]:
    body = section(text, "Practice Log")
    entries: list[PracticeEntry] = []
    current: dict[str, str] | None = None
    key_map = {
        "Date": "date",
        "Duration": "duration",
        "Result": "result",
        "Notes": "notes",
    }

    def finish() -> None:
        nonlocal current
        if not current:
            return
        entry = PracticeEntry(
            date=current.get("date", "").strip(),
            duration=current.get("duration", "").strip(),
            result=current.get("result", "").strip(),
            notes=current.get("notes", "").strip(),
        )
        if entry.date or entry.duration or entry.result or entry.notes:
            entry.minutes = parse_minutes(entry.duration)
            entry.days_ago = parse_days_ago(entry.date, today)
            entries.append(entry)
        current = None

    for line in body.splitlines():
        if line.startswith("- Date:"):
            finish()
            current = {"date": line.split(":", 1)[1].strip()}
            continue
        if current is None:
            continue
        match = re.match(r"\s{2,}(Date|Duration|Result|Notes):\s*(.*)$", line)
        if match:
            current[key_map[match.group(1)]] = match.group(2).strip()
        elif current.get("notes") and line.startswith("  "):
            current["notes"] += " " + line.strip()
    finish()
    return entries


def score_problem(path: Path, root: Path, today: date) -> ProblemRank:
    text = path.read_text(encoding="utf-8")
    title = parse_title(text)
    labels = parse_labels(text)
    attempts, status = parse_mastery(text)
    link = parse_link(text)
    entries = parse_practice_log(text, today)
    latest = entries[-1] if entries else None

    score = 0.0
    reasons: list[str] = []

    if latest is None:
        score += 18
        reasons.append("没有有效练习记录")
    else:
        weight = RESULT_WEIGHT.get(latest.result, 22 if latest.result else 12)
        score += weight
        if latest.result:
            reasons.append(f"最近结果: {latest.result}")
        if latest.minutes is not None:
            if latest.minutes >= 45:
                score += 20
                reasons.append(f"最近耗时较长: {latest.minutes}m")
            elif latest.minutes >= 30:
                score += 12
                reasons.append(f"最近耗时偏长: {latest.minutes}m")
            elif latest.minutes >= 20:
                score += 6
                reasons.append(f"最近耗时需要关注: {latest.minutes}m")
            elif latest.result == "一次性做对":
                score -= 6
                reasons.append(f"最近耗时较短: {latest.minutes}m")
        if latest.days_ago is not None:
            if latest.days_ago < 0:
                reasons.append(f"日期在未来: {latest.date}")
            elif latest.days_ago >= 21:
                score += 18
                reasons.append(f"距离上次练习 {latest.days_ago} 天")
            elif latest.days_ago >= 10:
                score += 10
                reasons.append(f"距离上次练习 {latest.days_ago} 天")
            elif latest.days_ago <= 2 and latest.result == "一次性做对":
                score -= 8
                reasons.append("最近刚一次做对")
        else:
            reasons.append("最近记录缺少可解析日期")

    weak_entries = [entry for entry in entries if entry.result in {"修改后做对", "参考答案后做对"}]
    if len(weak_entries) >= 2:
        bump = min(18, 6 * len(weak_entries))
        score += bump
        reasons.append(f"累计 {len(weak_entries)} 次非一次通过")

    mastery_bump = MASTERY_WEIGHT.get(status, 8 if status else 0)
    if mastery_bump:
        score += mastery_bump
        reasons.append(f"熟练度: {status or '未知'}")
    if "X" in attempts:
        score += min(12, attempts.count("X") * 4)
        reasons.append(f"Attempts 含 {attempts.count('X')} 次 X")
    if "H" in attempts:
        score += min(8, attempts.count("H") * 3)

    if any(label in CORE_LABELS for label in labels):
        score += 4

    return ProblemRank(
        score=round(score, 1),
        path=str(path.relative_to(root)),
        title=title,
        labels=labels,
        attempts=attempts,
        status=status,
        link=link,
        latest=latest,
        entry_count=len(entries),
        reasons=reasons[:6],
    )


def format_text(ranks: list[ProblemRank], limit: int) -> str:
    lines = []
    lines.append(f"Top {min(limit, len(ranks))} review candidates")
    lines.append("")
    for index, item in enumerate(ranks[:limit], 1):
        lines.append(f"{index}. {item.title} ({item.path})")
        lines.append(f"   score: {item.score}")
        if item.link:
            lines.append(f"   link: {item.link}")
        if item.labels:
            lines.append(f"   labels: {', '.join(item.labels)}")
        if item.attempts or item.status:
            lines.append(f"   mastery: Attempts={item.attempts or '-'}, Status={item.status or '-'}")
        if item.latest:
            latest_bits = []
            if item.latest.date:
                latest_bits.append(f"date={item.latest.date}")
            if item.latest.duration:
                latest_bits.append(f"duration={item.latest.duration}")
            if item.latest.result:
                latest_bits.append(f"result={item.latest.result}")
            if latest_bits:
                lines.append(f"   latest: {', '.join(latest_bits)}")
            if item.latest.notes:
                lines.append(f"   notes: {item.latest.notes}")
        lines.append(f"   reasons: {'; '.join(item.reasons) if item.reasons else '-'}")
        lines.append("")
    return "\n".join(lines).rstrip() + "\n"


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--root", default=".", help="Daily_Leetcode repository root")
    parser.add_argument("--limit", type=int, default=12, help="number of problems to print")
    parser.add_argument("--today", default=date.today().isoformat(), help="reference date, YYYY-MM-DD")
    parser.add_argument("--json", action="store_true", help="emit JSON instead of text")
    args = parser.parse_args()

    root = Path(args.root).resolve()
    today = date.fromisoformat(args.today)
    files = sorted((root / "problems").glob("**/lc*.md"))
    ranks = [score_problem(path, root, today) for path in files]
    ranks.sort(key=lambda item: (-item.score, item.path))

    if args.json:
        print(json.dumps([asdict(item) for item in ranks[: args.limit]], ensure_ascii=False, indent=2))
    else:
        print(format_text(ranks, args.limit), end="")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
