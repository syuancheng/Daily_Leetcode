# Bloom Filter Notes

## 1. What It Is

A Bloom filter is a space-efficient probabilistic data structure used to test whether an element may exist in a set.

Core rule:

- If it returns `false`, the element is definitely not in the set.
- If it returns `true`, the element may be in the set.

This means a Bloom filter can have false positives, but it does not have false negatives as long as items are only inserted and never removed.

## 2. How It Works

A Bloom filter usually contains:

- A bit array initialized to `false`.
- Several independent hash functions.

When adding a key:

1. Run the key through each hash function.
2. Convert each hash result into an index of the bit array.
3. Set all corresponding bits to `true`.

When checking a key:

1. Run the key through the same hash functions.
2. Check the corresponding bit positions.
3. If any bit is `false`, the key definitely does not exist.
4. If all bits are `true`, the key may exist.

## 3. Example From This Repository

The example in `bloom_filter.cpp` uses:

- `vector<bool>` as the bit array.
- `hash<string>{}` as one hash function.
- A polynomial rolling hash with base `131`.
- A `djb2`-style hash with multiplier `33`.

```cpp
void add(const string &key) {
  bits[hash1(key)] = true;
  bits[hash2(key)] = true;
  bits[hash3(key)] = true;
}

bool possiblyContains(const string &key) const {
  return bits[hash1(key)] && bits[hash2(key)] && bits[hash3(key)];
}
```

The method name `possiblyContains` is important because a `true` result is not guaranteed.

## 4. Main Features

- Space efficient: uses much less memory than storing all original keys.
- Fast insertion: usually O(k), where `k` is the number of hash functions.
- Fast query: also O(k).
- No original data storage: it only stores bits, not the actual keys.
- Probabilistic membership: query results are not always exact.

## 5. False Positives

A false positive means the Bloom filter says an element may exist even though it was never inserted.

This happens because different keys can set overlapping bit positions.

Example:

```text
Inserted: apple, banana, dog
Query: cat
Result: true
Meaning: cat may exist, but this could be a false positive
```

The false positive rate increases when:

- The bit array is too small.
- Too many keys are inserted.
- The hash functions are poorly distributed.
- The number of hash functions is not suitable for the array size and data volume.

## 6. No False Negatives

If `possiblyContains(key)` returns `false`, the key was definitely not inserted.

Reason: when a key is inserted, all of its hash positions are set to `true`. If any required bit is still `false`, that key could not have been inserted before.

This guarantee only holds for the normal insert-only Bloom filter. Deletion is not supported safely by a basic Bloom filter.

## 7. Common Uses

Bloom filters are useful when you need a fast pre-check before doing an expensive lookup.

Common examples:

- Database systems: check whether a key may exist before reading disk.
- Caches: avoid checking a cache or database for keys that definitely do not exist.
- Web crawlers: check whether a URL was probably visited.
- Distributed systems: reduce network calls for missing keys.
- Security systems: quick checks for blocked URLs, suspicious tokens, or known bad items.

## 8. Limitations

- It cannot tell you the stored value, only possible membership.
- It cannot list all inserted elements.
- It may return false positives.
- Basic Bloom filters do not support deletion.
- Choosing array size and hash count matters.

If deletion is needed, use a counting Bloom filter instead. It stores small counters instead of simple bits.

## 9. Complexity

Let:

- `n` be the number of inserted items.
- `m` be the bit array size.
- `k` be the number of hash functions.

Complexity:

- Insert: O(k)
- Query: O(k)
- Space: O(m)

## 10. Interview Summary

Use a Bloom filter when:

- Exact answers are not required for positive checks.
- False positives are acceptable.
- False negatives are not acceptable.
- Memory is limited.
- You want to avoid expensive lookups for definitely missing data.

The key sentence:

> Bloom filter says "definitely not present" or "possibly present".
