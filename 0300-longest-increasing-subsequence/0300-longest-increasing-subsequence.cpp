class Solution {
public:
    int lengthOfLIS(vector<int>& v) {
        int n = v.size();
        vector<int>ans;
        ans.push_back(v[0]);
        for(int i = 1;i<n;++i){
          if(v[i] > ans.back()){
              ans.push_back(v[i]);
          }else{

              auto low = lower_bound(ans.begin(),ans.end(),v[i])- ans.begin();
              ans[low] = v[i];
          }
        }
        return (int)ans.size();
    }
};