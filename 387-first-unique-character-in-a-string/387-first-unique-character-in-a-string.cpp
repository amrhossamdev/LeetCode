class Solution {
public:
    int firstUniqChar(string s) {
        map<char,int>mp;
        for(auto c:s){
            mp[c]++;
        }
        int i=0;
        for(auto c:s){
            if(mp[c]==1)return i; 
            i++;
        }
        return -1;
    }
};