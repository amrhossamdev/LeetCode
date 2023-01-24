class Solution {
public:
    
    int findJudge(int n, vector<vector<int>>& trust) {
        bool townjudge[n + 1];
        memset(townjudge,true,sizeof(townjudge));
        for(int i =0;i<trust.size();++i){
           townjudge[trust[i][0]] = false;
        }
        int ans = 0;
        for(int i = 1;i<=n;++i){
            if(townjudge[i]) {ans = i;break;}
        }
        int cnt = 0;
        for(int i =0;i<trust.size();++i){
            if(trust[i][1] == ans){
                cnt++;
            }
        }
        if(cnt== n-1)return ans;
        return -1;
    }
};