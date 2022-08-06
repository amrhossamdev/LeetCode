class Solution {
public:
    int numJewelsInStones(string j, string s) {
        if(j.size()>s.size())swap(j,s);
        int ans=0;
        for(int i=0;i<j.size();++i){
            for(int k=0;k<s.size();++k){
                if(s[k] == j[i])++ans;
            }
        }
        return ans;
    }
};