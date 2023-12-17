class Solution {
public:
    vector <vector<int>> divideArray(vector<int> &nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector <vector<int>> ans;
        vector<int> v;
        map<int, int> mp;
        for (int i = 0; i < n; ++i) {
            if (v.size() == 3) {
                ans.push_back(v);
                v.clear();
            }
            v.push_back(nums[i]);
        }
        if (v.size() == 3) {
                ans.push_back(v);
                v.clear();
            }
        map<int, set<int>> adj;
        for (int i = 0; i < ans.size(); ++i) {
            adj[ans[i][0]].insert(0);
            for (int j = 1; j < ans[i].size() - 1; ++j) {
                adj[ans[i][j]].insert(j);
                if (ans[i][j+1] - ans[i][j - 1] > k) return {};
            }
        }
       
        return ans;
    }
};