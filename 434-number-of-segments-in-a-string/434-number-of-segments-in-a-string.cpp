class Solution {
public:
    int countSegments(string s) {
        int ans = 0, n = s.length();
        if (n == 0)return 0;
        if (n == 1 && s[0] == ' ')return 0;
        for (int i = 1; i < n; i++) if (s[i] == ' ' && s[i - 1] != ' ')ans++;
        if (s[n - 1] == ' ') return ans;
        else return ans + 1;
    }
};