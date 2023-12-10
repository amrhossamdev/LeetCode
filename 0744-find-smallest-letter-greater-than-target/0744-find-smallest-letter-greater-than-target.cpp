class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        vector<int>freq(26,0);
        int n = letters.size();
        for(int i = 0;i<n;++i){
            freq[letters[i]-'a']++;
        }
        for(char c = target+1;c<='z';++c){
            if(freq[c-'a'])return c;
        }
        return letters[0];
    }
};