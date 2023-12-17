class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        multiset<int>st;
        int p1,p2;
        for(int i = 0;i<n;++i){
            for(int j = 0;j<n;++j){
                st.insert(grid[i][j]);
            }
        }
        for(int i = 1;i<=n*n;++i){
            if(st.find(i) == st.end()){
                p1 = i;
            }
            if(st.count(i)>1){
                p2 = i;
            }
        }
        return {p2,p1};
    }
};