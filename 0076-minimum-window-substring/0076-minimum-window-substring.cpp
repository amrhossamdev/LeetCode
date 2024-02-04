class Solution {
 public:
  map<char, int> have;
  map<char, int> mp;
  bool check() {
    bool ok = 1;
    for (auto i : have) {
      ok &= (i.second <= mp[i.first]);
    }
    return ok;
  }
  string minWindow(string s, string t) {
    int n = s.size();
    int m = t.size();

    for (int i = 0; i < m; ++i) {
      have[t[i]]++;
    }
    int l = 0, r = 0;

    int ll = 0, rr = 0;
    int sz = 1e9;
    while (l < n) {
      while (r < n && !check()) {
        mp[s[r]]++;
        r++;
      }
      if (check() && sz > r - l + 1) {
        sz = r - l + 1;
        ll = l, rr = r;
      }
      mp[s[l]]--;
      l++;
    }
    string ans;
    for (int i = ll; i < rr; ++i) {
      ans += s[i];
    }
    return ans;
  }
};