class Solution {
public:

    const int N = 1e6 + 5;

    int minimumCardPickup(vector<int> &cards) {
        unordered_map<int, int> mp;
        int res = INT_MAX, n = cards.size();
        for (int i = 0; i < n; ++i) {
            mp[cards[i]] = -1;
        }
        for (int i = 0; i < n; ++i) {
            int cur = cards[i];
            if (mp[cur] == -1) {
                mp[cur] = i;
            } else {
                if (mp[cur] < i) {
                    res = min(res, i - mp[cur] + 1);
                }
                mp[cur] = i;
            }
        }

        return (res == INT_MAX ? -1 : res);

    }
};