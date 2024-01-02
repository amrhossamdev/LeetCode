class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        
        multiset<int>st;
        vector<vector<int>>ans;
        int n = nums.size();
        for(int i =0;i<n;++i){
            st.insert(nums[i]);
        }
        while(!st.empty()){
            vector<int>tmp;
            for(int i =1;i<=n;++i){
                auto it= st.find(i);
                if(it!=st.end()){
                    tmp.push_back(*it);
                    st.erase(it);
                }
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};