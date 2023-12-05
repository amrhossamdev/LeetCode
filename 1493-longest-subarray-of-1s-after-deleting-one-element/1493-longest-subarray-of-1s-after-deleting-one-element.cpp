class Solution {
 public:
  int longestSubarray(vector<int>& nums) {
    int n = nums.size();
    int ans = 0;
    int cnt = 0;
    int l  =0,r = 0;
    int ones =0;
    bool ch =0;
    while(l<n){
        while(r<n && cnt<2){
            if(!nums[r] && cnt)break;
            cnt+=!nums[r];
            ones+=nums[r];
            r++;
        }
        ch|=cnt;
        ans = max(ans,ones);
        cnt-=!nums[l];
        ones-=nums[l];
        l++;
    }
    return ans - (!ch ? 1 : 0);
  }
};