class Solution {
 public:
  int minDeletionSize(vector<string>& v) {
    int ans = 0;
    for (int col = 0; col < v[0].size(); ++col) {
         bool ch = false;
      for (int row = 1; row < v.size(); ++row) {
        if (v[row-1][col] > v[row][col] && !ch) {
          ++ans;
          ch = true;
        }
      }
    }
  return ans;
  }
};