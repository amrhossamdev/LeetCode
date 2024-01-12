class Solution {
 public:
  bool check(char c) {
     
    return c == 'a' || c == 'i' || c == 'e' || c == 'o' || c == 'u';
  }
  bool calc(string& s) {
    int n = s.size();
    bool ans = 1;
    ans&=check(s.front());
    ans&=check(s.back());
    return ans;
  }
  int vowelStrings(vector<string>& words, int left, int right) {
    int n = words.size();
    int pre[n];
    pre[0] = calc(words[0]);
    for (int i = 1; i < n; ++i) {
      pre[i] = pre[i - 1] + calc(words[i]);
    }
    return pre[right] - (left > 0 ? pre[left - 1] : 0);
  }
};