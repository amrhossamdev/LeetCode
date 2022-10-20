class Solution {
public:
     int freq[26];
     int freq2[26];
    int rearrangeCharacters(string s, string target) {
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            freq[s[i]-'a']++;
        }
        for (int i = 0; i < target.size(); ++i) {
            freq2[target[i]-'a']++;
        }
        int res = INT_MAX;
        for (int i = 0; i < target.size(); ++i) {
            res = min(freq[target[i]-'a'] / freq2[target[i]-'a'], res);
        }
        return res;

    }
};