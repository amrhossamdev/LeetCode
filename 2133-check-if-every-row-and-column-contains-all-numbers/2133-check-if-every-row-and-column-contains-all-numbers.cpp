class Solution {
 public:
  bool checkValid(vector<vector<int>>& v) {
    int n = v.size();
    for (int i = 0; i < n; i++) {
      vector<int> freq(n, 0);
      for (int j = 0; j < n; j++) {
        freq[v[i][j] - 1] = 1;
      }
      for (auto i : freq) {
        if (i == 0) return false;
      }
      for (int j = 0; j < n; j++) {
        freq[v[j][i] - 1] = 0;
      }
      for (auto i : freq) {
        if (i == 1) return false;
      }
    }
    return true;
  }
  };