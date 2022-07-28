class Solution {
public:
    vector<int> topKFrequent(vector<int>& v, int k) {
        vector<int>ans;
        map<int,int>mp;
        vector<pair<int,int>>vp;
        for(int i =0;i<v.size();++i){
            mp[v[i]]++;
        }
        for(auto i:mp){
            vp.push_back({i.second,i.first});
        }
        sort(vp.rbegin(),vp.rend());
        for(int i =0;i<k;++i){
            //cout<<vp[i].first << " " << vp[i].second<<endl;
            ans.push_back(vp[i].second);
        }
        return ans; 
    }
};