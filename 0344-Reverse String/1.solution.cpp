#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  void reverseString(vector<char>& s) {
    size_t size = s.size();
    if (size <= 1)
      return;

    size_t i = 0;
    size_t j = size - 1;
    while (i < j) {
      swap(s[i], s[j]);
      i++;
      j--;
    }
  }
};