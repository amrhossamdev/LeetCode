class Solution {
public:
    void sortColors(vector<int>& v) {
        int z =0,o=0,t=0;
        int n =v.size();
        for(int i =0;i<n;++i){
            if(v[i] ==0)++z;
            else if(v[i] == 1)++o;
            else {
                t++;
            }
        }
        int i = 0;
        while(z||o||t){
            if(z){v[i++]=0;z--;}
            else if(o){v[i++]=1;o--;}
            else if(t){v[i++] = 2;t--;}
        }
    }
};