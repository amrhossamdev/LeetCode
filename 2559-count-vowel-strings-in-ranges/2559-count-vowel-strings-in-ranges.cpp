class Solution {
public:
    bool check(string &s) {
        bool front = s[0] == 'a' || s[0] == 'e' || s[0] == 'i' || s[0] == 'o' || s[0] == 'u';
        bool back = s.back() == 'a' || s.back() == 'e' || s.back() == 'i' || s.back() == 'o' || s.back() == 'u';
        return front && back;
    }

    vector<int> vowelStrings(vector <string> &words, vector <vector<int>> &queries) {
        int n = words.size();
        int pre[n + 1];
        pre[0] = check(words[0]);
        for (int i = 1; i < n; ++i) {
            pre[i] = pre[i - 1] + check(words[i]);
        }
        vector<int> ans;
        for (int i = 0; i < queries.size(); ++i) {
            int l = queries[i][0];
            int r = queries[i][1];
            if (l == 0) {
                ans.push_back(pre[r]);
            } else {
                ans.push_back(pre[r] - pre[l - 1]);
            }
        }
        return ans;
    }
};