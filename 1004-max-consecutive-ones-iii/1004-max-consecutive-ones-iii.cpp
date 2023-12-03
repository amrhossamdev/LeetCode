class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int l =0,r = 0;
        int mx = -1e9;
        int cnt = 0;
        int tmp = k;
        while(l<n){
            while(r<n && (nums[r] || tmp)){
                if(!tmp && !nums[r]){break;}
                if(!nums[r] && tmp)tmp--;
                r++;
            }
            mx = max(mx,r-l);
            tmp+=!nums[l];
            l++;
        }
        return mx;
    }
};