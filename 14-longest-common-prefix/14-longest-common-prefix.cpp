class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string s = strs[0];
        for (int i = 1; i < n; ++i) {
            string s2 = strs[i];
            for (int j = 0; j < s.size(); ++j) {
                if (s2[j] != s[j]) {
                    s.erase(s.begin()+j,s.end());
                }
            }
        }
        return s;
    }
};