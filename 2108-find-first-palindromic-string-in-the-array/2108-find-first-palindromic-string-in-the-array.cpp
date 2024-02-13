class Solution {
 public:
  string firstPalindrome(vector<string>& words) {
    int n = words.size();
    for (int i = 0; i < n; ++i) {
      string s = words[i];
      string tmp = s;
      reverse(tmp.begin(), tmp.end());
      if (tmp == s) return s;
    }

    return "";
  }
};