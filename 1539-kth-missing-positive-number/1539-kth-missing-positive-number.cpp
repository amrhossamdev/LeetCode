class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        set<int>st;
        int cnt = 0;
        for(int i = 0;i<arr.size();++i){
           st.insert(arr[i]);
        }
        int end  = (*st.rbegin() + k);
        for(int i =1;i<= end;++i){
            if(st.find(i) == st.end()){
             ++cnt;   
            }
            if(cnt == k) return i;
        }
        if(cnt == 0)return end;
        return 0;
    }
};