



#include <vector>
int main() {
  // 滑动窗口
  std::vector<int> nums;
  // 暴力
  for (int i = 0; i < nums.size(); i++) {
    for (int j = i; j < nums.size(); j++) {
    
    }
  }

  // 真正滑动窗口
  int left = 0, right = 0;
  while (right < nums.size()) {
    // 增加窗口
    right++;

    while (/*需要缩小*/) {
      left++;
    }
  }


  return 0;
}