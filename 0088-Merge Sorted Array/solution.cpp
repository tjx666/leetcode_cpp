#include <algorithm>
#include <vector>

class Solution {
 public:
  void merge(std::vector<int>& nums1, size_t m, std::vector<int>& nums2, size_t n) {
    auto iter = nums1.begin();
    auto end = iter + m;
    size_t j = 0;

    while (j < n) {
      iter = std::upper_bound(iter, end, nums2[j]);
      if (iter == end) {
        for (; j < n; j++, iter++) {
          *iter = nums2[j];
        }
        return;
      }

      for (auto iter1 = end - 1; iter1 >= iter; iter1--) {
        *(iter1 + 1) = *iter1;
      }
      *iter = nums2[j];
      end++;
      j++;
    }
  }
};

int main() {
  std::vector nums1{4, 5, 6, 0, 0, 0};
  std::vector nums2{1, 2, 3};
  Solution s;
  s.merge(nums1, 3, nums2, 3);
}