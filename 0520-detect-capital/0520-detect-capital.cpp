class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.size();
        int capitalCnt = 0;
        bool isInFirst = (word[0] < 97);
        for(int i =0;i<n;++i){
            capitalCnt += (word[i] < 97);
        }
        if(capitalCnt == word.size())return true;
        else if(capitalCnt == 1 && isInFirst){return true;}
        else if(capitalCnt == 0) return true;
        return false;
    }
};