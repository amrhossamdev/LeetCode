class Solution {
public:
    bool findSubarrays(vector<int>& v) {
        unordered_set<int>st;
        for(int i =1;i<v.size();++i){
            int sum = v[i-1] + v[i];
            if(st.empty()){
                st.insert(sum);
            }else{
                if(st.find(sum) != st.end()){
                    return true;
                }else{
                    st.insert(sum);
                }
            }
        }
        return false;
    }
};