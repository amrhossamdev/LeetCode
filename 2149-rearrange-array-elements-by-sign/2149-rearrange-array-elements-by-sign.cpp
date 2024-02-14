class Solution {
 public:
  vector<int> rearrangeArray(vector<int>& v) {
    vector<int> pos, neg, ans;
    int n = v.size();
    for (int i = 0; i < n; ++i) {
      if (v[i] > 0) {
        pos.push_back(v[i]);
      } else {
        neg.push_back(v[i]);
      }
    }
    bool turn = 1;
    int i1 = 0, i2 = 0;
    for (int i = 0; i < n; ++i) {
      if (turn) {
        ans.push_back(pos[i1++]);
      } else {
        ans.push_back(neg[i2++]);
      }

      turn ^= 1;
    }
    return ans;
  }
};