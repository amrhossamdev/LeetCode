class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> mp1;
        map<char, int> mp2;
        for (int i = 0; i < s.size(); i++) {
            mp1[s[i]]++;
        }
        for (int i = 0; i < t.size(); ++i) {
            mp2[t[i]]++;
        }
        for (auto i:mp1) {
            if (mp2[i.first] != i.second)return false;
        }
         for (auto i:mp2) {
            if (mp1[i.first] != i.second)return false;
        }
        return true;
    }
};