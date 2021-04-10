#include <vector>

/**
 * 条件：
 * 0 <= nums.length <= 3 * 104
 * -104 <= nums[i] <= 104
 * nums 已按升序排列
 * 
 * 思路：
 * 快慢双指针，慢指针保存插入位置，快指针遍历
 * 
 * 复杂度：
 * 时间复杂度：n，也就是快指针遍历一个循环
 * 空间复杂度：0，原地操作
 * 
 */
class Solution {
 public:
  int removeDuplicates(std::vector<int>& nums) {
    size_t length = nums.size();
    if (length < 2)
      return length;

    // slow 表示可以插入下一个不同元素的前一个元素的下标，其实也是最后一个不同元荤素的下标
    // 例如：1, 2, 3, 3, 4，当快指针遍历到 3 时 slow 是 1，下一个可插入不同元素的下标是 2
    size_t slow = 0;
    for (size_t fast = 1; fast < length; fast++) {
      if (nums[fast] != nums[fast - 1]) {
        nums[slow + 1] = nums[fast];
        slow++;
      }
    }

    return slow + 1;
  }
};

int main() {
  std::vector<int> nums{1, 2, 3, 3, 4};
  Solution s;
  s.removeDuplicates(nums);

  return 0;
}