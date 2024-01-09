class Solution {
public:
    string reverseStr(string s, int k) {
        string tmp = s;
        reverse(tmp.begin(), tmp.end());
        if (k >= s.size()) {
            return tmp;
        }
        string str, str2;
        int cnt = 0;
        int seg = 0;
        string ans;
        for (int i = 0; i < s.size(); ++i) {
            ++cnt;
            if (cnt <= k) {
                str += s[i];
            } else {
                str2 += s[i];
            }
            if (cnt >= 2 * k) {
                reverse(str.begin(), str.end());
                ans += str;
                ans += str2;
                cnt = 0;
                seg = 0;
                str2 = "",str = "";
            }
        }
        if(str.size()){
          reverse(str.begin(), str.end());
            ans+=str;
        }
        if(str2.size())ans+=str2;
        return ans;
    }
};