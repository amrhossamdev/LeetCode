class Solution {
 public:
  bool checkValid(vector<vector<int>>& v) {
    map<int, int> mp;
    int n = v[0].size();
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        mp[v[i][j]]++;
      }
      if (mp.size() != n) {
        return false;
      }
      for (auto i : mp) {
        if (i.second != 1) return false;
      }
      mp.clear();
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        mp[v[j][i]]++;
      }
      if (mp.size() != n) {
        return false;
      }
      for (auto i : mp) {
        if (i.second != 1) return false;
      }
      mp.clear();
    }
    return true;
  }
};