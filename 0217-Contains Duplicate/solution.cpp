#include <unordered_set>
#include <vector>

class Solution {
 public:
  bool containsDuplicate(std::vector<int>& nums) {
    /**
     * unordered_set find 的时间复杂度是 o1，基于 hash 表
     * set find 时间复杂度是 0lgn，有序是基于红黑树
     */
    std::unordered_set<int> s;
    for (auto num : nums) {
      if (s.find(num) != s.end())
        return true;
      s.emplace(num);
    }
    return false;
  }
};

int main() {
  std::vector<int> nums{1, 0, 1, 1};
  Solution solution;
  solution.containsDuplicate(nums);
}