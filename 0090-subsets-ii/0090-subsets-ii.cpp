class Solution {
 public:
  vector<vector<int>> subsetsWithDup(vector<int>& v) {
    int n = v.size();
    vector<vector<int>> ans;
    set<vector<int>> st;
    for (int msk = 0; msk < 1 << n; ++msk) {
      vector<int> subset = {};
      for (int i = 0; i < n; ++i) {
        if (msk & (1 << i)) {
          subset.push_back(v[i]);
        }
      }
      sort(subset.begin(), subset.end());
      if (st.find(subset) == st.end()) {
        ans.push_back(subset);
        st.insert(subset);
      }
    }
    return ans;
  }
};