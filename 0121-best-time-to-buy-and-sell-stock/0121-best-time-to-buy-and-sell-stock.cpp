class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        int mx = -1e9;
        int mn = 1e9;
    
        int suff[n];
        suff[n - 1] = prices[n - 1];
        for(int i = n - 2;i>=0;i--){
            suff[i] = max(suff[i + 1],prices[i]);
        }
     
        int ans = 0;
        for(int i = 0;i<n - 1;++i){
            mn = min(mn,prices[i]);
            ans = max(ans,suff[i + 1] - mn);
        }
        return ans;
        
    }
};