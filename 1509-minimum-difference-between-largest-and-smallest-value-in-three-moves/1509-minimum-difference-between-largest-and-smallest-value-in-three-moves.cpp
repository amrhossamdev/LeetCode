class Solution {
public:
    int minDifference(vector<int>& nums) {
        if(nums.size() <= 4) return 0;
        int n =nums.size();
        priority_queue<int>mxPq;
         priority_queue<int,vector<int>,greater<int>> mnPq;
        for(int i =0;i<n;++i){
            mxPq.push(nums[i]);
            if(mxPq.size()>4){mxPq.pop();}
             mnPq.push(nums[i]);
            if(mnPq.size()>4){mnPq.pop();}
        }
        vector<int>mxList,mnList;
        while(!mxPq.empty()){
            mxList.push_back(mxPq.top());
            mxPq.pop();
        }
         while(!mnPq.empty()){
            mnList.push_back(mnPq.top());
            mnPq.pop();
        }
        int res = INT_MAX;
        for(int i = 0;i<4;++i){
            res = min(res,abs(mxList[i] - mnList[3-i]));
        }
        return res;
    }
};