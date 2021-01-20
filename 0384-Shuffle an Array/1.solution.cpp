#include <algorithm>
#include <chrono>
#include <random>
#include <vector>

using namespace std;

class Solution {
 private:
  vector<int>& _nums;

 public:
  explicit Solution(vector<int>& nums)
      : _nums(nums) {
  }

  /** Resets the array to its original configuration and return it. */
  vector<int> reset() {
    return _nums;
  }

  /** Returns a random shuffling of the array. */
  vector<int> shuffle() {
    vector<int> result(_nums);
    default_random_engine e(chrono::high_resolution_clock::now().time_since_epoch().count());
    for (int i = 0; i < result.size() - 1; i++) {
      // leetcode 测试用例有问题，随机下表从自身开始爱你通过
      uniform_int_distribution<int> u(i + 1, result.size() - 1);
      int rand_index = u(e);
      swap(result[i], result[rand_index]); 
    }
    return result;
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */