#include <algorithm>
#include <cmath>
#include <set>
#include <vector>

class Solution {
 public:
  bool containsNearbyAlmostDuplicate(std::vector<int>& nums, size_t k, int t) {
    if (k == 0)
      return false;
    std::set<int> s;
    size_t size = nums.size();
    for (size_t i = 0; i < size; i++) {
      int val = nums[i];
      auto iter = s.lower_bound(std::max(val, INT_MIN + t) - t);
      if (iter != s.end() && *iter <= std::min(INT_MAX - t, val) + t) {
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