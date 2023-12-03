class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int l =0,r = 0;
        int mx = -1e9;
        while(l<n){
            while(r<n && (nums[r] || k)){
                if(!k && !nums[r]){break;}
                if(!nums[r] && k)k--;
                r++;
            }
            mx = max(mx,r-l);
            k+=!nums[l];
            l++;
        }
        return mx;
    }
};