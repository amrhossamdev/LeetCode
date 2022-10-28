class Solution {
public:
    
    long long count(long long mid,vector<int>&v,int h){
        long long sum = 0;
        for(int i=0;i<v.size();++i){
                sum+=(ceil(1.0*v[i]/mid));
            }
        return sum<=h;
    }

    int minEatingSpeed(vector<int> &v, int h) {
     
        long long l = 1, r = *max_element(v.begin(),v.end());
        long long ans =r;
        while (l <= r) {
            long long sum = 0;
            long long m = (l+r)/2;
            if(count(m,v,h)){
                ans = min(ans,m);
                r = m - 1;
            }else {
                l = m + 1;
            }
        }
        return ans;
    }
};