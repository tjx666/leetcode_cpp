#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  bool searchMatrix(vector<vector<int>> matrix, int target) {
    auto row = lower_bound(matrix.begin(), matrix.end(), target, [](const vector<int>& a, const int b) {
      return a[0] < b;
    });

    if (row != matrix.end() && (*row)[0] == target)
      return true;

    if (row == matrix.begin())
      return false;

    row--;
    return binary_search(row->begin(), row->end(), target);
  }
};