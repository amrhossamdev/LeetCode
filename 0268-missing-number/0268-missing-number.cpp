class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int tmp = 0;
        int n = nums.size();
        int sum = n*(n+1)/2;
        int ans = 0;
        for(int i = 0;i<n;++i){
            ans+=nums[i];
        }
        return sum - ans;
    }
};