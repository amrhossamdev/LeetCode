class Solution {
 public:
  char findTheDifference(string s, string t) {
    s+=t; 
    int c=0;
    for(auto x: s){
        c^=x;
    }
    return char(c);
  }
};