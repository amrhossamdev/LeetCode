class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        int suffixMax[n];
        suffixMax[n-1] = arr[n-1];
        for(int i = n-2;i>=0;i--){
            suffixMax[i] = max(suffixMax[i+1],arr[i]);
        }
        vector<int>ans;
        for(int i = 0;i<n-1;++i){
            ans.push_back(suffixMax[i+1]);
        }
        ans.push_back(-1);
        return ans;
    }
};