#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  int maximumProduct(vector<int>& nums) {
    int max1 = -1000;
    int max2 = -1000;
    int max3 = -1000;
    int min1 = 1000;
    int min2 = 1000;
    int min3 = 1000;
    for (size_t i = 0; i < nums.size(); i++) {
      int val = nums[i];

      if (val > max1) {
        max3 = max2;
        max2 = max1;
        max1 = val;
      } else if (val > max2) {
        max3 = max2;
        max2 = val;
      } else if (val > max3) {
        max3 = val;
      }

      if (val < min1) {
        min3 = min2;
        min2 = min1;
        min1 = val;
      } else if (val < min2) {
        min3 = min2;
        min2 = val;
      } else if (val < min3) {
        min3 = val;
      }
    }

    return max({max1 * max2 * max3, min1 * min2 * min3, max1 * min2 * min1});
  }
};