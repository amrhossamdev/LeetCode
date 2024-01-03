class Solution {
public:
    int numberOfBeams(vector <string> &bank) {
        int n = bank.size();
        int m = bank[0].size();
        long long ans = 0;

        int floors = 0;
        int prev =-1;
        for (int i = 0; i < n; ++i) {
            int cnt = 0;
            for (int j = 0; j < m; ++j) {
                cnt += bank[i][j] == '1';
            }
            if(prev !=-1 && cnt!=0){
                ans+=cnt*prev;
            }
            if (cnt)++floors;
            if(cnt!=0)
            prev = cnt;
        }

        return (floors >= 2 ? ans : 0);
    }
};