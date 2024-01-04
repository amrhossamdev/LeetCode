class Solution {
 public:
  string removeKdigits(string s, int k) {
    stack<char> st;
    int n = s.size();

    for (int i = 0; i < n; ++i) {
      while (k > 0 && !st.empty() && s[i] < st.top()) {
        st.pop();
        k--;
      }
      st.push(s[i]);
    }
    string ans;
    while (!st.empty()) {
      ans += st.top();
      st.pop();
    }
    while (ans.size() && ans.back() == '0') ans.pop_back();
    reverse(ans.begin(), ans.end());
    while (ans.size() && k) {
      ans.pop_back();
      k--;
    }
    if (ans.empty()) ans += '0';
    return ans;
  }
};