class Solution {
 public:
  long long countSubarrays(vector<int>& v, int k) {
    int freq = 0;
    int l = 0, r = 0;
    int mx = *max_element(v.begin(), v.end());
    long long ans = 0;
    int n = v.size();
      for(int r = 0;r<n;++r){
          if(v[r] == mx){
              ++freq;
          }
          while(freq>k || (l<=r && freq == k && v[l] != mx)){
              if(v[l] == mx){
                  freq--;
              }
              l++;
          }
          if(freq == k){
              ans+= l  + 1;
          }
      }

    return ans;
  }
};