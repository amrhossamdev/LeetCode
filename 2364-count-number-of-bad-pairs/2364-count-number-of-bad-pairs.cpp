class Solution {
public:
    long long countBadPairs(vector<int>& v) {
        unordered_map<int, int>mp;
        long long n = v.size();
        long long p = n*(n-1)/2;//total pairs
        long long goodpairs=0;
        for(int i =0;i<v.size();++i){
            long long cur = i-v[i];
            goodpairs+=mp[cur];
            mp[cur]++;
        }
        return p-goodpairs;
    }
};