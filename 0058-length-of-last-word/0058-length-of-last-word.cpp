class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int len = 0;
        bool found = 0;
        for(int i = n-1;i>=0;--i){
            if(found && s[i] == ' ')break;
            if(s[i] != ' '){
                len++;
                found = 1;
            }
        }
        return len;
    }
};