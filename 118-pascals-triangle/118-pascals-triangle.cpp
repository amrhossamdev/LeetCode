class Solution {
public:
    vector <vector<int>> generate(int n) {

        vector <vector<int>> ans;
        if (n > 1) {
            ans.push_back({1});
            ans.push_back({1, 1});
            for (int i = 2; i < n; ++i) {
                vector<int> v(i + 1);
                v[0] = 1;
                v[v.size() - 1] = 1;
                for (int j = 0; j < ans[i - 1].size() - 1; j++) {
                    v[j + 1] = ans[i - 1][j] + ans[i - 1][j + 1];
                }
                ans.push_back(v);
            }
            return ans;
        } else {
            return {{1}};
        }
    }
};