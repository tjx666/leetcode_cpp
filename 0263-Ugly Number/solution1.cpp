/**
 * 给你一个整数 n ，请你判断 n 是否为丑数。如果是，返回 true；否则，返回 false 。
 * 丑数：只包含质因数 2、3 和/或 5 的正整数。
 * -2^31 <= n <= 2^31 - 1
 */

class Solution {
 public:
  bool isUgly(int n) {
    if (n == 1) return true;
    
    if (n < 2)
      return false;

    while (n % 2 == 0) {
      n /= 2;
    }

    while (n % 3 == 0) {
      n /= 3;
    }

    while (n % 5 == 0) {
      n /= 5;
    }

    return n == 1;
  }
};

int main() {
  Solution s;
  s.isUgly(6);
  return 0;
}