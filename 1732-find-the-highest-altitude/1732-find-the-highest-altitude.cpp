class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int sm = 0;
        int ans = 0;
        for(int i = 0;i<gain.size();++i){
            sm+=gain[i];
            ans = max(ans,sm);
        }
        return ans;
    }
};