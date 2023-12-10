class Solution {
public:
    bool hasAlternatingBits(int n) {
        int leftMostBit = 0;
        for(int i =30;i>=0;--i){
          if(n & (1<<i)){
              leftMostBit = i;
              break;
          }
        }
        int prev = (n &(1<<0))>0;
        for(int i = 1;i<=leftMostBit;++i){
            if(prev == (n&(1<<i))>0)return false;
            prev =((n &(1<<i))>0);
        }
        return true;
    }
};