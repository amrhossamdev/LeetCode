class Solution {
public:
   
    int minFlipsMonoIncr(string s) {
        int cnt = 0;
        int flips = 0;
        for(char ch : s) {
            if(ch == '1') {
                cnt++;
            }
            else {
                flips = min(flips + 1, cnt);
            }
        }
        return flips;
    }
};