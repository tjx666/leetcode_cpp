#include <vector>

/**
 * 会做 26 就会做这个
 */
class Solution {
 public:
  int removeDuplicates(std::vector<int>& nums) {
    size_t length = nums.size();
    if (length < 3)
      return length;

    size_t slow = 0;

    for (size_t fast = 1, same_count = 1; fast < length; fast++) {
      if (nums[fast] != nums[fast - 1]) {
        nums[slow + 1] = nums[fast];
        slow++;
        same_count = 1;
      } else {
        same_count++;
        if (same_count == 2) {
          nums[slow + 1] = nums[fast];
          slow++;
        }
      }
    }

    return slow + 1;
  }
};