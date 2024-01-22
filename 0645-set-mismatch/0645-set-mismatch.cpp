class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        map<int,int>mp;
        for(int i = 0;i<nums.size();++i){
            mp[nums[i]]++;
        }
        int twice = 0;
        for(auto i : mp){
            if(i.second == 2){
                twice = i.first;
            }
        }
        for(int i = 1;i<=nums.size();++i){
            if(mp.find(i) == mp.end()){
                return {twice,i};
            }
        }
        return {1,1};
    }
};