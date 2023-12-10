class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans = 0;
        for (int i = 0; i < 30; ++i) {
            int x1 = (start & (1 << i)) > 0;
            int x2 = (goal & (1 << i)) > 0;
            if (x1 != x2)++ans;
        }
        return ans;
    }
};