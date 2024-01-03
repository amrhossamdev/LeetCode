class Solution {
public:
    string generateTheString(int n) {
        string tmp;
        for(int i = 0;i<n;++i){
            tmp+='a';
        }
        if(!(n&1) && tmp.size()){
            tmp.pop_back();
            tmp+='b';
        }
        return tmp;
    }
};