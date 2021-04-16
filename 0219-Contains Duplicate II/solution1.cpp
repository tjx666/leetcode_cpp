#include <vector>
#include <unordered_map>

class Solution {
 public:
  bool containsNearbyDuplicate(std::vector<int>& nums, size_t k) {
    std::unordered_map<int, size_t> map;
    size_t size = nums.size();
    for (size_t i = 0; i < size; i++) {
      int val = nums[i];
      auto iter = map.find(val);
      if (iter != map.end() && i - iter->second <= k) {
        return true;
      }
      map[val] = i;
    }
    return false;
  }
};

int main() {
  std::vector<int> nums{1, 0, 1, 1};
  Solution solution;
  solution.containsNearbyDuplicate(nums, 1);
}