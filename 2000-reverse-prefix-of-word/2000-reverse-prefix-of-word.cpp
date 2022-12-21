class Solution {
public:
    string reversePrefix(string s, char ch) {
        int n = s.size();
        for(int i = 0;i<n;++i){
            if(s[i] == ch){
                reverse(s.begin(),s.begin() + i + 1);
                break;
            }
        }
        return s;
    }
};