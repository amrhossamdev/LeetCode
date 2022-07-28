class Solution {
public:
    vector<int> topKFrequent(vector<int>& v, int k) {
        vector<int>ans;
        map<int,int>mp;
        priority_queue<pair<int,int>> pq; 
        for(int i =0;i<v.size();++i){
            mp[v[i]]++;
        }
        for(auto i:mp){
            pq.push({i.second,i.first});
        }
        for(int i =0;i<k;++i){
            //cout<<vp[i].first << " " << vp[i].second<<endl;
           ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans; 
    }
};