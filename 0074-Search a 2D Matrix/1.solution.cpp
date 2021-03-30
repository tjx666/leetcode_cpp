#include <vector>

using namespace std;

/**
 * 时间复杂度：m + n
 * 空间复杂度：0
 */
class Solution {
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    const int rowCount = matrix.size();
    const int columnCount = matrix[0].size();

    int i = 0;
    int j = columnCount - 1;

    while (i < rowCount && j >= 0) {
      int val = matrix[i][j];
      if (target > val) {
        i++;
      } else if (target < val) {
        j--;
      } else {
        return true;
      }
    }

    return false;
  }
};