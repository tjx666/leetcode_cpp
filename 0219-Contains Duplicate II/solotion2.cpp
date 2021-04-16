#include <unordered_set>
#include <vector>

/**
 * 利用无序的滑动窗口
 */
class Solution {
 public:
  bool containsNearbyDuplicate(std::vector<int>& nums, size_t k) {
    if (k == 0)
      return false;
    std::unordered_set<int> s;
    size_t size = nums.size();
    for (size_t i = 0; i < size; i++) {
      int val = nums[i];
      if (s.find(val) != s.end()) {
        return true;
      }
      if (s.size() == k) {
        s.erase(nums[i - k]);
      }
      s.emplace(val);
    }
    return false;
  }
};