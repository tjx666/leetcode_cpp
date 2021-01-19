#include <vector>

using namespace std;

/*
注意点：
1. 任意两个元素不相等
2. 下标为 -1 和 n 可以视为无穷小
意味着：
取中间坐标 m 和右边的坐标 m + 1 比较，首先只有可能大于或小于
m > m + 1，左边必定存在峰值，因为 -1 下标值为负无穷，最不济就是 0 下标
m < m + 1 同理。
3. 还有需要注意的就是取中间下标是向下取整，这样当只有两个元素时比较的就是这俩元素，如果向上取整就超出下标了
*/
class Solution {
 public:
  int findPeakElement(vector<int>& nums) {
    int left = 0;
    int right = nums.size() - 1;
    int mid;

    while (left < right) {
      mid = (left + right) / 2;
      if (nums[mid] > nums[mid + 1]) {
        right = mid;
      }
      // 除了大于就是小于，题目说了相邻元素不相等
      else {
        left = mid + 1;
      }
    }

    return left;
  }
};