class Solution {
public:
    int minSteps(string s, string t) {
        vector<int>freq1(26,0),freq2(26,0);
        for(int i = 0;i<s.size();++i){
            freq1[s[i]-'a']++;
            freq2[t[i]-'a']++;
        }
        int diff = 0;
        for(int i = 0;i<26;++i){
            diff+=abs(freq1[i]-freq2[i]);
        }
        return diff/2;
    }
};