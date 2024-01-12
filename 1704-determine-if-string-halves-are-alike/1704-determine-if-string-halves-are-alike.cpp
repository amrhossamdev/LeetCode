class Solution {
public:
    
    bool calc(char c){
        return c== 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    bool halvesAreAlike(string s) {
        int n = s.size();
        for(int i= 0;i<n;++i){
            s[i] = tolower(s[i]);
        }
        if(n&1)return false;
        int cnt1 = 0,cnt2 = 0;
        for(int i = 0;i<n/2;++i){
            cnt1+=calc(s[i]);
        }
        for(int i = n/2;i<n;++i){
            cnt2+=calc(s[i]);
        }
        return cnt1 == cnt2;
    }
};