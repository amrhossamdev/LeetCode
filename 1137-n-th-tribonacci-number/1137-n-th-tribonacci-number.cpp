class Solution {
public:
    int tribonacci(int n) {
        int trib[1000];
        trib[0] = 0;
        trib[1] = 1;
        trib[2] = 1;
        // 0 1 2 3 
        // 0 1 1 2
        for(int i = 3;i<=n;++i){
            trib[i] = trib[i-1] + trib[i-2] + trib[i-3];
        }
        return trib[n];
    }
};