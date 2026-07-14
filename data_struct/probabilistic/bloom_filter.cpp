
#include <cstddef>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class BloomFilter {
private:
  vector<bool> bits;
  size_t size;

  size_t hash1(const string &s) const { return hash<string>{}(s) % size; }

  size_t hash2(const string &s) const {
    size_t h = 0;
    for (char c : s) {
      h = h * 131 + static_cast<unsigned char>(c);
    }
    return h % size;
  }

  size_t hash3(const string &s) const {
    size_t h = 5381;
    for (char c : s) {
      h = ((h << 5) + h) + static_cast<unsigned char>(c); // h * 33 + c
    }
    return h % size;
  }

public:
  explicit BloomFilter(size_t n) : bits(n, false), size(n) {}

  void add(const string &key) {
    bits[hash1(key)] = true;
    bits[hash2(key)] = true;
    bits[hash3(key)] = true;
  }

  bool possiblyContains(const string &key) const {
    return bits[hash1(key)] && bits[hash2(key)] && bits[hash3(key)];
  }
};

int main() {
  BloomFilter bf(100);

  bf.add("apple");
  bf.add("banana");
  bf.add("dog");

  cout << boolalpha;

  cout << "apple: " << bf.possiblyContains("apple") << endl;
  cout << "dog: " << bf.possiblyContains("dog") << endl;
  cout << "cat: " << bf.possiblyContains("cat") << endl;

  return 0;
}
