class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        deque<int>dq;
        int n = nums.size();
        double sm = 0;
        for(int i = 0;i<k;++i){
            dq.push_back(nums[i]);
            sm+=nums[i];
        }
        double ans = sm/k;
        for(int i = k;i<n;++i){
            sm-=dq.front();
            dq.pop_front();
            dq.push_back(nums[i]);
            sm+=dq.back();
            ans = max(sm/k,ans);
        }
        return ans;
    }
};