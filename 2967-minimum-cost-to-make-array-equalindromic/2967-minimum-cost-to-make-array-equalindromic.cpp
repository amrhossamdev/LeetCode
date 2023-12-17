class Solution {
public:

    bool check(string s) {
        string tmp = s;
        reverse(tmp.begin(), tmp.end());
        return tmp == s;
    }


    long long getHigher(long long x,vector<int> &nums) {
        long long mid;
        for(int i = x;i<=1e9;++i){
            if(check(to_string(i))){
                mid = i;
                break;
            }
        }
        long long ans = 0;
        for(int i  = 0;i<nums.size();++i){
            ans+=abs(mid - nums[i]);
        }
        return ans;
    }
    
    long long getLower(long long x,vector<int> &nums) {
        long long mid;
        for(int i = x - 1;i>=0;--i){
            if(check(to_string(i))){
                mid = i;
                break;
            }
        }
        long long ans = 0;
        for(int i  = 0;i<nums.size();++i){
            ans+=abs(mid - nums[i]);
        }
        return ans;
    }

    long long minimumCost(vector<int> &nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        long long mid = nums[n / 2];
        return min(getHigher(mid,nums),getLower(mid,nums));
    }
};