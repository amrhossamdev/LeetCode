class Solution {
public:
    int appendCharacters(string s, string t) {
        int n = s.size();
        int j = 0;
        for(int i = 0; i< n;++i){
            if(t[j] == s[i]){
                ++j;
            }
        }
        return (int)t.size() - j;
    }
};