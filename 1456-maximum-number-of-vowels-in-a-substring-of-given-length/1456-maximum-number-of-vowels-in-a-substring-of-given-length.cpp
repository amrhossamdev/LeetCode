class Solution {
 public:
  bool isVowel(char c) {
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
  }
  int maxVowels(string s, int k) {
    deque<char> dq;
    int n = s.size();
    int ans = 0;
    int cnt = 0;
    for (int i = 0; i < k; ++i) {
      dq.push_back(s[i]);
      cnt += isVowel(s[i]);
    }
    ans = cnt;
    for (int i = k; i < n; ++i) {
      cnt -= isVowel(dq.front());
      dq.pop_front();
      dq.push_back(s[i]);
      cnt += isVowel(dq.back());
      ans = max(ans, cnt);
    }
    return ans;
  }
};