#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  void backtrace(vector<string>& ans, string& path, int open, int close, int n) {
    if (open + close == n * 2) {
      ans.emplace_back(path);
      return;
    }

    if (open < n) {
      path.push_back('(');
      backtrace(ans, path, open + 1, close, n);
      path.pop_back();
    }

    if (close < open) {
      path.push_back(')');
      backtrace(ans, path, open, close + 1, n);
      path.pop_back();
    }
  }

  vector<string> generateParenthesis(int n) {
    vector<string> ans;
    string path;
    backtrace(ans, path, 0, 0, n);
    return ans;
  }
};