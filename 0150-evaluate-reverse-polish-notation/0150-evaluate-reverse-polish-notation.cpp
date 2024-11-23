class Solution {
 public:
  int evalRPN(vector<string>& s) {
    stack<int> st;
    int ans = 0;
    int n = s.size();
    for (int i = 0; i < n; ++i) {
      string cur = s[i];
      if (st.empty()) {
        st.push(stoi(cur));
      } else {
        if (cur == "+") {
          auto x = st.top();
          st.pop();
          auto y = st.top();
                      st.pop();
          st.push(y + x);
        } else if (cur == "*") {
          auto x = st.top();
          st.pop();
          auto y = st.top();
                      st.pop();
          st.push(x * y);
        } else if (cur == "/") {
          auto x = st.top();
          st.pop();
          auto y = st.top();
          st.pop();
          st.push(y / x);
        } else if (cur == "-") {
          auto x = st.top();
          st.pop();
          auto y = st.top();
          st.pop();
          st.push(y - x);
        } else {
          st.push(stoi(cur));
        }
      }
    }
    ans = st.top();
    return ans;
  }
};