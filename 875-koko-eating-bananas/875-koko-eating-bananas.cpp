class Solution {
public:


    int minEatingSpeed(vector<int> &v, int h) {
     
        long long l = 1, r = *max_element(v.begin(),v.end());
        int ans =r;
        while (l <= r) {
            long long sum = 0;
            int m = (l+r)/2;
            for(int i=0;i<v.size();++i){
                sum+=(ceil(1.0*v[i]/m));
            }
            if(sum<=h){
                ans = min(ans,m);
                r = m - 1;
            }else {
                l = m + 1;
            }
        }
        return ans;
    }
};