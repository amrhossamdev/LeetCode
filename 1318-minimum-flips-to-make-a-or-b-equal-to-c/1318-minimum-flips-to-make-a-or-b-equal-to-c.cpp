class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans = 0;
        for (int i = 0; i < 30; ++i) {
            if (c & (1 << i)) {
                if (!(a & (1 << i)) && !(b & (1 << i)))++ans;
            } else {
                ans+=(a&(1<<i))>0;
                ans+=(b&(1<<i))>0;
            }
        }
        return ans;
    }
};