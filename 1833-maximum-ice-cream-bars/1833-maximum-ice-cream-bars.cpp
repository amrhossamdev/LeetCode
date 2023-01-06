class Solution {
public:
    
    int maxIceCream(vector<int>& costs, int coins) {
        int n = costs.size();
        int ans = 0;
        sort(costs.begin(),costs.end());
        for(int i =0;i<n;++i){
            if(coins>=costs[i]){
                ++ans;
                coins-=costs[i];
            }
        }
        return ans;
    }
};