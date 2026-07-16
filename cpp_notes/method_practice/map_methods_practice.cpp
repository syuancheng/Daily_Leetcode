#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

void printTitle(const string &title) {
  cout << "\n========== " << title << " ==========\n";
}

void printMap(const map<string, int> &scores) {
  cout << "{";
  bool first = true;
  for (const auto &[key, value] : scores) {
    if (!first) {
      cout << ", ";
    }
    first = false;
    cout << key << ": " << value;
  }
  cout << "}\n";
}

void printUnorderedMap(const unordered_map<char, int> &freq) {
  cout << "{";
  bool first = true;
  for (const auto &[key, value] : freq) {
    if (!first) {
      cout << ", ";
    }
    first = false;
    cout << key << ": " << value;
  }
  cout << "}\n";
}

void demoMapBasic() {
  printTitle("std::map basic");

  map<string, int> scores;
  scores["alice"] = 90;
  scores["bob"] = 85;
  scores.insert({"cindy", 92});
  scores.emplace("david", 88);

  cout << "map is ordered by key: ";
  printMap(scores);

  cout << "scores[\"alice\"]: " << scores["alice"] << '\n';
  cout << "scores.at(\"bob\"): " << scores.at("bob") << '\n';

  cout << "count alice: " << scores.count("alice") << '\n';
  cout << "find eric exists: " << (scores.find("eric") != scores.end()) << '\n';

  scores["alice"] = 95;
  cout << "update alice: ";
  printMap(scores);

  scores.erase("bob");
  cout << "erase bob: ";
  printMap(scores);
}

void demoMapBounds() {
  printTitle("std::map lower_bound / upper_bound");

  map<int, string> table = {{10, "ten"}, {20, "twenty"}, {30, "thirty"}};

  auto lower = table.lower_bound(20);
  if (lower != table.end()) {
    cout << "lower_bound(20): " << lower->first << " -> " << lower->second
         << '\n';
  }

  auto upper = table.upper_bound(20);
  if (upper != table.end()) {
    cout << "upper_bound(20): " << upper->first << " -> " << upper->second
         << '\n';
  }

  cout << "iterate key/value:\n";
  for (const auto &[key, value] : table) {
    cout << "  " << key << " => " << value << '\n';
  }
}

void demoOperatorBracketTrap() {
  printTitle("operator[] creates missing keys");

  map<string, int> counter;
  cout << "initial size: " << counter.size() << '\n';

  cout << "counter[\"missing\"]: " << counter["missing"] << '\n';
  cout << "size after operator[]: " << counter.size() << '\n';

  map<string, int> safer;
  cout << "safer.find(\"missing\") exists: "
       << (safer.find("missing") != safer.end()) << '\n';
  cout << "size after find: " << safer.size() << '\n';
}

void demoUnorderedMapFrequency() {
  printTitle("std::unordered_map frequency");

  string text = "banana";
  unordered_map<char, int> freq;
  for (char ch : text) {
    ++freq[ch];
  }

  cout << "frequency of banana: ";
  printUnorderedMap(freq);

  cout << "freq['a']: " << freq['a'] << '\n';
  cout << "contains z: " << (freq.find('z') != freq.end()) << '\n';
}

void demoGroupByMap() {
  printTitle("group by with map");

  vector<string> words = {"apple", "ape", "banana", "boat", "cat"};
  map<char, vector<string>> groups;

  for (const string &word : words) {
    groups[word[0]].push_back(word);
  }

  for (const auto &[firstChar, items] : groups) {
    cout << firstChar << ": ";
    for (const string &item : items) {
      cout << item << " ";
    }
    cout << '\n';
  }
}

void practiceArea() {
  printTitle("practice area");

  // Practice 1: count character frequency in a string.
  // Practice 2: find the first character whose frequency is 1.
  // Practice 3: group words by their first letter.
  // Practice 4: use map<int, int> to count sorted number frequencies.
  cout << "Edit practiceArea() or add your own functions, then rerun this "
          "file.\n";
}

int main() {
  cout << boolalpha;

  // demoMapBasic();
  // demoMapBounds();
  // demoOperatorBracketTrap();
  // demoUnorderedMapFrequency();
  demoGroupByMap();
  // practiceArea();

  return 0;
}
