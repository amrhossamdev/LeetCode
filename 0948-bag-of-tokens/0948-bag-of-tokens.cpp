class Solution {
 public:
  
  int bagOfTokensScore(vector<int> &tokens, int power) {
      
      multiset<int>st;
      int n = tokens.size();
      for(int i = 0;i<n;++i){
          st.insert(tokens[i]);
      }

      int score = 0;
      while(!st.empty()){
          auto cur =  *st.begin();
          st.erase(st.find(cur));
          if(power >= cur){
              score++;
              power-=cur;
          }else{
              if(st.size() && score){
                st.insert(cur);
                auto back = prev(st.end());
                power+= *back;
                score--;
                st.erase(back);
              }
          }
      }
    
    return score;
  }
};