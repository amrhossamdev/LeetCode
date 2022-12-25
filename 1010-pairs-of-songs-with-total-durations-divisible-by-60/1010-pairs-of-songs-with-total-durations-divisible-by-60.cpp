class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& v) {
        int n = v.size();
        int ans = 0;
        unordered_map<int, int> mp;
        for(int i =0;i<n;++i){
            v[i]%=60;
            int num = (v[i] ==0 ? 60:v[i]);
            if(mp.find(60 -num) != mp.end()){
                ans+=mp[60-num];
            }
            mp[v[i]]++;
        }
        return ans;
    }
};