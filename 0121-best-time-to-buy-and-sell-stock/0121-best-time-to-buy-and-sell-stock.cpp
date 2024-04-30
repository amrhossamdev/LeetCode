class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        int profit = 0;
        int mn = prices[0];
        
        for(int i = 0;i<n;++i){
            profit = max(profit,prices[i] - mn);
            mn = min(mn,prices[i]);
        }
        
        return profit;
        
    }
};