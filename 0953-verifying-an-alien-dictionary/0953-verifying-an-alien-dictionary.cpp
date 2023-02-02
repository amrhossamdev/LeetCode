class Solution {
public:
    bool isAlienSorted(vector <string> &words, string order) {
        map<char, int> mp;
        for (int i = 0; i < 26; i++) {
            mp[order[i]] = i;
        }
        for (int i = 0; i < words.size() - 1; i++) {
            int szn = words[i].size(), szn1 = words[i + 1].size(), j = 0;
            while (j < szn) {
                if (j == szn1) return false;
                if (mp[words[i][j]] == mp[words[i + 1][j]])
                    j++;
                else if (mp[words[i][j]] > mp[words[i + 1][j]])
                    return false;
                else
                    break;
            }
        }
        return true;
    }
};