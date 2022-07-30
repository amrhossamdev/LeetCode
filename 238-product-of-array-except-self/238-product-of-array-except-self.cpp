class Solution {
public:
    vector<int> productExceptSelf(vector<int>& v) {
        int n = v.size();
        vector<int>suf(n);
        vector<int>pre(n);
        pre[0] = 1,suf[0] = 1;
        for(int i =1;i<n;++i){
            pre[i] = pre[i-1]*v[i-1];
            suf[i] = suf[i-1]*v[n-i];
        }
        vector<int>ans;
        for(int i =0;i<n;++i){ ans.push_back(pre[i]*suf[n-1-i]);}
        return ans;
    }
};