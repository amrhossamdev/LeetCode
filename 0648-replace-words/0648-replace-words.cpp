class Solution {
public:
    string replaceWords(vector <string> &dic, string word) {

        map<string, bool> have;

        int n = dic.size();
        for (int i = 0; i < n; ++i) {
            have[dic[i]] = true;
        }

        n = word.size();
        string ans = "";
        string tmp = "";
        bool found = 0;
        for (int i = 0; i < n; ++i) {
            int pos = i;
            found = 0;
            while (pos < n && word[pos] != ' ') {

                if (!found) {
                    tmp += word[pos];
                    if (have[tmp]) {
                        ans += tmp + " ";
                        tmp = "";
                        found = 1;
                    }
                }

                ++pos;
            }
            if (!found) {
                ans += tmp + " ";
                tmp = "";
            }
            i = pos;
        }
        ans.pop_back();
        return ans;
    }
};