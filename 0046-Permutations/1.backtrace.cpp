#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> result;
    backtrace(0, nums, result);
    return result;
  }

  void backtrace(int start, vector<int>& nums, vector<vector<int>>& result) {
    if (start == nums.size()) {
      result.push_back(nums);
      return;
    }

    for (int i = start; i < nums.size(); i++) {
      swap(nums[start], nums[i]);
      backtrace(start + 1, nums, result);
      swap(nums[start], nums[i]);
    }
  }
};
