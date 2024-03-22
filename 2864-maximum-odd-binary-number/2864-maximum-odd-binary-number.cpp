class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        string ans;
        int ones = 0;
        int n = s.size();
        for(int i = 0;i<n;++i){
            ones+=(s[i] == '1');
        }
        ones--;
        for(int i = 0;i<ones;++i){
            ans+='1';
        }
        for(int i = 0;i<n - (ones + 1);++i){
            ans+='0';
        }
        ans+='1';
        return ans;
    }
};