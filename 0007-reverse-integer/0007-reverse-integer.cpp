class Solution {
public:
    int reverse(int x) {
        bool sign = (x<0);
        long long ans = 0;
        long long cur = 1;
        long long tmp = x;
        long long cnt = 0;
        x = abs(x);
        tmp = x;
        while(tmp>0){
           tmp/=10;
            ++cnt;
        }
        
        while(x>0){
           ans+=(x%10) *pow(10,cnt-1);
           x/=10;
           cnt--;
        }
        long long res = (sign?-1:1)*ans;
        if(res<INT_MIN|| res>INT_MAX)return 0;

        return res;
    }
};