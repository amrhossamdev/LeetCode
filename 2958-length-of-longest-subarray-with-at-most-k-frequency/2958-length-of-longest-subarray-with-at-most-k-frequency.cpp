class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>mp;
        int l = 0,r = 0;
        int ans = -1e9;
        while(l<n){
            while(r<n && mp[nums[r]]+1<=k){
                mp[nums[r]]++;
                r++;
            }
            ans = max(ans,r-l);
        
            mp[nums[l++]]--;
                
        }
        return ans;
    }
};