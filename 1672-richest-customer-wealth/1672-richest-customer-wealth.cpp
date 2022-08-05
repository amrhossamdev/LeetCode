class Solution {
public:
    int maximumWealth(vector <vector<int>> &v) {
        int ans = INT_MIN;
        for (int i = 0; i < v.size(); i++) {
            int res = 0;
            for (int j = 0; j < v[i].size(); ++j) {
                res += v[i][j];
            }
            ans = max(res, ans);
        }
        return ans;
    }
};