class Solution {
public:
    int numIdenticalPairs(vector<int>& v) {
        int ans = 0;
        unordered_map<int,int>mp;
        for(auto i:v){ans+=mp[i]++;}
        return ans;
    }
};