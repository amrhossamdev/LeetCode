class Solution {
public:
    void sortColors(vector<int>& nums) {
        int r =0,w = 0,b = 0;
        int n = nums.size();
        for(int i = 0;i<n;++i){
            r+=nums[i] == 0;
            w+= nums[i] == 1;
            b+=nums[i] == 2;
        }
        for(int i = 0;i<n;++i){
            if(r>0){
                nums[i] = 0;
                r--;
            }else if(w>0){
                nums[i] = 1;
                w--;
            }else{
                nums[i]=2;
                b--;
            }
        }
        
    }
};