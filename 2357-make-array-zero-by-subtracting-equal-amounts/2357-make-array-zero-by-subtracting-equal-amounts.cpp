class Solution {
public:
    int minimumOperations(vector<int>& v) {
        set<int>st(v.begin(),v.end());
        if(*st.begin()==0)return st.size()-1;
        return st.size();
    }
};