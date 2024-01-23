class Solution {
public:
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        int ans = 0;        
        for(int msk = 0;msk<(1<<n);++msk){
            vector<int>freq(26,0);
            int cnt = 0;
            for(int i = 0;i<n;++i){
                if(msk & (1 << i)){
                    bool ok = true;
                    for(int j = 0 ;j<arr[i].size();++j){
                        ok&=freq[arr[i][j] - 'a'] == 0;
                        freq[arr[i][j]-'a']++;
                    }
                    if(ok){
                        cnt+=arr[i].size();
                    }
                }
            }
            ans = max(ans,cnt);
        }
        return ans;
    }
};