class Solution {
public:
    int lastStoneWeight(vector<int>& v) {
        if(v.size() == 1)return v[0];
        priority_queue<int>pq;
        for(int i =0;i<v.size();++i){
            pq.push(v[i]);
        }
   
        while(!pq.empty()){
            int top = pq.top();
            pq.pop();
            if(pq.top() == top){pq.pop();}
            else {
                int t = pq.top();
                pq.pop();
                pq.push(top-t);
            }
            if(pq.size() ==1){return pq.top();}
        }
        return 0;
    }
};