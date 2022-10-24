class Solution {
 public:
  int longestConsecutive(vector<int>& v) {
    unordered_set<int> st(v.begin(), v.end());
    int ans = 0;
    for (auto i : st) {
      if (st.find(i + 1) == st.end()) {
        int cnt = 0;
        while (st.find(i) != st.end()) {
          i--;
          ++cnt;
        }
        ans = max(cnt, ans);
      }
    }
    return ans;
  }
};