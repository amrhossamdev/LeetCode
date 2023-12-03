class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        deque<char> dq1(word1.begin(), word1.end()), dq2(word2.begin(), word2.end());
        int n = word1.size();
        int m = word2.size();
        string ans;
        bool turn = 1;
        while (!dq1.empty() && !dq2.empty()) {

            if (turn) {
                if (dq1.size()) {
                    ans += dq1.front();
                    dq1.pop_front();
                }
            } else {
                if (dq2.size()) {
                    ans += dq2.front();
                    dq2.pop_front();
                }
            }
            turn ^= 1;
        }

        while (!dq1.empty()){
            ans += dq1.front();
            dq1.pop_front();
        }
        while (!dq2.empty()){
            ans += dq2.front();
            dq2.pop_front();
        }
        return ans;
    }
};