#include <iostream>
#include <vector>

using namespace std;

class Solution {
 private:
  void backtrace(vector<int>& nums, vector<int>& path, vector<vector<int>>& result, int count, int start) {
    if (path.size() == count) {
      result.emplace_back(path);
      return;
    }

    for (int i = start; i <= nums.size() + path.size() - count; i++) {
      if (i != start && nums[i] == nums[i - 1])
        continue;
      path.emplace_back(nums[i]);
      backtrace(nums, path, result, count, i + 1);
      path.pop_back();
    }
  }

 public:
  vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> path;
    sort(nums.begin(), nums.end());
    for (int count = 0; count <= nums.size(); count++) {
      backtrace(nums, path, result, count, 0);
    }
    return result;
  }
};