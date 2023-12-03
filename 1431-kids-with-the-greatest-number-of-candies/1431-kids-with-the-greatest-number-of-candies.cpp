class Solution {
 public:
  vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
    int mx = -1e9;
    for (int i = 0; i < candies.size(); ++i) {
      mx = max(mx, candies[i]);
    }
    vector<bool> ans(candies.size());
    for (int i = 0; i < candies.size(); ++i) {
      ans[i] = (candies[i] + extraCandies >= mx);
    }
    return ans;
  }
};