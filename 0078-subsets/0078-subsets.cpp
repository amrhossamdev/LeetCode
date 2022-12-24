class Solution {
public:
    vector<vector<int>> subsets(vector<int>& v) {
        int n = v.size();
        vector<vector<int>>ans;
        for(int msk = 0;msk < 1<<n;++msk){
            vector<int> subset = {};
            for(int i = 0;i<n;++i){
                if(msk & (1<<i)){
                    subset.push_back(v[i]);
                }
            }
            ans.push_back(subset);
        }
        return ans;
    }
};