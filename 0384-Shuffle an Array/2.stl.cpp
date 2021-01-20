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
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    vector<int> result(_nums);
    std::shuffle(result.begin(), result.end(), default_random_engine(seed));
    return result;
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */