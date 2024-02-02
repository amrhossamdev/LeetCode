class Solution {
public:

    vector<int> sequentialDigits(int low, int high) {
        vector<int> v;
        for(int i = 1;i<=9;++i)v.push_back(i);
        int n = v.size();
        vector<int>ans;
        for(int i = 0;i<n;++i){
            string tmp;
            for(int j = i;j<n;++j){
                tmp+=to_string(v[j]);
                if(stoi(tmp)>=low && stoi(tmp)<=high){
                    ans.push_back(stoi(tmp));
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};