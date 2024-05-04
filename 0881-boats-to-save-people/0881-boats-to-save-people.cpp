class Solution {
public:
    

    int numRescueBoats(vector<int>& v, int limit) {
        int n = v.size();
        sort(v.begin(),v.end());
        int l = 0,r = n - 1;
        int ans = 0;
        
        while(l<=r){
            if(v[l] + v[r] <=limit){
                l++;
            }
            ++ans;
            r--;
        }
        return ans;
        
    }
};