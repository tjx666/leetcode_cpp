#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
    vector<vector<int>> result;
    int left = toBeRemoved[0];
    int right = toBeRemoved[1];

    for (size_t i = 0; i < intervals.size(); i++) {
      vector<int> interval = intervals[i];
      int start = interval[0];
      int end = interval[1];

      if (left >= end || right <= start) {
        result.push_back({start, end});
      } else {
        if (left > start) {
          result.push_back({start, left});
        }

        if (right < end) {
          result.push_back({right, end});
        }
      }
    }

    return result;
  }
};