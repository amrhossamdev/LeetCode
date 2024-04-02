class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char>st={};
        map<char,char>ts={};
        for(int i =0;i<s.length();++i){
            char c1 = s[i],c2= t[i];
            if(st.count(c1) && st[c1] != c2 ||ts.count(c2) && ts[c2] != c1)return false;
            st[c1] = c2;
            ts[c2] = c1;
        }
        return true;
    }
};