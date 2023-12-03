class Solution {
 public:
  bool isVowel(char c) {
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
  }
  int maxVowels(string s, int k) {
    int n = s.size();
    int pre[n];
    pre[0] = isVowel(s[0]) ? 1 : 0;
    for (int i = 1; i < n; ++i) {
      pre[i] = pre[i - 1] + isVowel(s[i]);
    }
    int ans = pre[k - 1];
    for (int i = k; i < n; ++i) {
      ans = max(ans, pre[i] - pre[i - k]);
    }
    return ans;
  }
};