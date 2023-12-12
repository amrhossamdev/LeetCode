class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n = candyType.size();
        set<int>st;
        for(int i = 0;i<candyType.size();++i){
            st.insert(candyType[i]);
        }
        return min(n/2,(int)st.size());
    }
};