class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        set<int>st;
        vector<int>ans;
        int n = s.size();
        for(int i = 0;i<n;++i){
            if(s[i] == c)st.insert(i);
        }
        for(int i = 0;i<n;++i){
            auto it = st.lower_bound(i);
            int val = *it;
            int mn = val - i;
            if(s[val]!=c)mn = 1e9;
            if(mn<0)mn = 1e9;
            --it;
            if(it!=st.end()){
                mn = min(abs(i - *it),mn);
            }
            ans.push_back(mn);
        }
        return ans;
    }
};