#include <vector>

using namespace std;

/*
 * 参考：https://leetcode-cn.com/problems/diagonal-traverse/solution/xiao-bai-kan-guo-lai-zui-zhi-bai-yi-li-jie-ban-ben/
 */
class Solution {
 public:
  vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
    vector<int> result;
    int m = matrix.size();
    if (m == 0)
      return result;
    int n = matrix[0].size();
    if (n == 0)
      return result;

    int i_max = m + n - 1;
    int x = 0;
    int y = 0;
    for (int i = 0; i < i_max; i++) {
      if (i % 2 == 0) {
        while (x >= 0 && y < n) {
          result.emplace_back(matrix[x][y]);
          x--;
          y++;
        }
        if (y < n) {
          x++;
        } else {
          x += 2;
          y--;
        }
      } else {
        while (y >= 0 && x < m) {
          result.emplace_back(matrix[x][y]);
          x++;
          y--;
        }

        if (x < m) {
          y++;
        } else {
          x--;
          y += 2;
        }
      }
    }
    return result;
  }
};