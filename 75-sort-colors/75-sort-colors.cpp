class Solution {
public:
    void sortColors(vector<int>& v) {
        priority_queue<int,vector<int>,greater<int>>pq;
        int n =v.size();
        for(int i =0;i<n;++i){
            pq.push(v[i]);
        }
        int i = 0;
        while(!pq.empty()){
            v[i++] = pq.top();
            pq.pop();
        }
    }
};