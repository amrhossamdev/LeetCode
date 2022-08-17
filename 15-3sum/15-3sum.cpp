class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& v) {
        vector<vector<int>>ans;
        sort(v.begin(),v.end());
        if(v.size()<3)return {};
        for(int i = 0;i<v.size();++i){
            if(i>0 && v[i-1]==v[i])continue;
            int l =i+1,r=v.size()-1;
              while(l<r){
              if(v[i]+v[l]+v[r]==0){
                  ans.push_back({v[i],v[l],v[r]});
                  ++l;
                  while(v[l]==v[l-1] && l<r){
                      ++l;
                  }             
                }
              if(v[i]+v[l]+v[r]>0){r--;}else{l++;}
        
            }

        }
        

        return ans;
    }
};