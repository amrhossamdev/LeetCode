class Solution {
public:
    vector<int> twoSum(vector<int>& v, int k) {
        map<int,int>mp;
        for(int i =0;i<v.size();++i){
            mp[v[i]] = i;
        }
        for(int i =0;i<v.size();++i){
            if(mp[k-v[i]] != 0 && i != mp[k-v[i]]){
                return {i,mp[k-v[i]]};
            }
        }
        return {};
    }
};