class Solution {
public:
    int largestSumAfterKNegations(vector<int> &nums, int k) {
        int n = nums.size();
        int haveNegative = 0;
        int ans = 0;
        for (int i = 0; i < n; ++i)haveNegative |= (nums[i] < 0);
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            if (nums[i] < 0 && k) {
                nums[i] = -nums[i];
                k--;
            }
            ans+=nums[i];
        }
        sort(nums.begin(), nums.end());
        if (k & 1) {
            return ans - 2 * nums[0];
        } else {
            return ans;
        }
    }
};