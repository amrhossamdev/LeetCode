class Solution {
 public:
  string reverseWords(string s) {
    string ans = "";
    int n = s.size();
    string tmp = "";
    for (int i = n - 1; i >= 0; i--) {
      if (s[i] != ' ') {
        tmp += s[i];
      } else {
        if (tmp.size()) {
          reverse(tmp.begin(), tmp.end());
          ans += tmp;
          ans += ' ';
          tmp = "";
        }
      }
    }

    if (tmp.size()) {
      reverse(tmp.begin(),tmp.end());
      ans += tmp;
    }
    while (!ans.empty() && ans.back() == ' ') {
      ans.pop_back();
    }
    return ans;
  }
};