class Solution {
 public:
  int totalFruit(vector<int>& v) {
    map<int, int> mp;
    int ans = 0;
    int l = 0, r = 0;
    int n = v.size();
    while (r < n) {
      mp[v[r]]++;
      r++;
      while (mp.size() > 2) {
        mp[v[l]]--;
        if (mp[v[l]] == 0) mp.erase(v[l]);
        l++;
      }
      ans = max(r - l, ans);
    }
    return ans;
  }
};