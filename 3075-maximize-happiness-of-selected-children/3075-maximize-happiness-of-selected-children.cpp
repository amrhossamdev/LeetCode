class Solution {
public:
    long long maximumHappinessSum(vector<int>& v, int k) {
        long long ans = 0;
        int have = 0;
        int n = v.size();
        
        sort(v.rbegin(),v.rend());
        for(int i = 0;i<n && have<k;++i){
            if(v[i] - have >=0){
               ans+= v[i] - have;
                ++have;
            }
        }
        return ans;
    }
};