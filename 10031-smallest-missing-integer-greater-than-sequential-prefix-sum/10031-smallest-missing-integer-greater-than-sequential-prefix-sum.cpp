class Solution {
public:
    int missingInteger(vector<int>& v) {
        int n = v.size();
        int sm = v[0];
        int ans = -1e9;
        map<int,int>mp;
        for(int i = 0;i<n;++i){
            mp[v[i]]++;
        }
        for(int i = 1;i<n;++i){
            if(v[i] - v[i - 1] == 1){
                ++ans;
                sm+=v[i];
            }else{
                break;
            }
        }
        ans = max(ans,sm);
        while(mp[ans]){
            ++ans;
        }
        return ans;
    }
};