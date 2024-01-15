class Solution {
 public:
  vector<vector<int>> findWinners(vector<vector<int>>& matches) {
    vector<vector<int>> ans(2);
    int n = matches.size();
    map<int, int> mp;
    set<int> players;
    for (int i = 0; i < n; ++i) {
      int win = matches[i][0];
      int lose = matches[i][1];
      players.insert(win);
      players.insert(lose);
      mp[lose]++;
    }
    for(auto i : players){
        if(!mp[i])ans[0].push_back(i);
    }
    for (auto i : mp) {
      if (i.second == 1) {
        ans[1].push_back(i.first);
      }
    }
    return ans;
  }
};