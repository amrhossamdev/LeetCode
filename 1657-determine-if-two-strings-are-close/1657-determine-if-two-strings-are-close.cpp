class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        if (n != m)return false;
        map<char, int> mp1, mp2;
        multiset<int> st;
        set<char> ch;
        for (int i = 0; i < n; ++i) {
            mp1[word1[i]]++;
        }
        for (int i = 0; i < m; ++i) {
            mp2[word2[i]]++;
        }
        for (char c = 'a'; c <= 'z'; ++c) {
            if (mp1[c] && !mp2[c] || !mp1[c] && mp2[c])return false;
        }

        for (auto i: mp1) {
            st.insert(i.second);
        }
        for (auto i: mp2) {
            auto res = st.find(i.second);
            if (res != st.end())
                st.erase(res);
            else {
                return false;
            }
        }
        return (st.empty());
    }
};