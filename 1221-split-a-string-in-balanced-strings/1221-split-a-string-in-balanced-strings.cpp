class Solution {
public:
    int balancedStringSplit(string s) {
         vector<string> v;
    int l = 0;
    int r = 0;
    bool isL = false;
    if (s[0] == 'L') isL = true;

        for (char i : s) {
        string s("");
        if (i == 'L') {
            ++l;
        } else if (i == 'R') {
            ++r;
        }
        if (l == r) {
            for (int j = 0; j < l; ++j) {
                s += 'L';
            }
            for (int j = 0; j < l; ++j) {
                s += 'R';
            }
            if (!isL) reverse(s.begin(),s.end());
            v.push_back(s);
            l = 0, r = 0;
        }
    }
    return v.size();
    }
};