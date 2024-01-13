class Solution {
 public:
  int minSteps(string s, string t) {
    map<char, int> mp1, mp2;
    int n = s.size();
    for (int i = 0; i < n; ++i) {
      mp2[t[i]]++;
      mp1[s[i]]++;
    }
    int ans = 0;
    for (char c = 'a'; c <= 'z'; ++c) {
      if (mp2[c] < mp1[c]) {
        for (char k = 'a'; k <= 'z'; ++k) {
          if (mp2[k] > mp1[k]) {
            ans += mp2[k] - mp1[k];
            mp2[k] -= (mp2[k] - mp1[k]);
            mp2[c] += (mp2[k] - mp1[k]);
          }
        }
      }
    }
    return ans;
  }
};