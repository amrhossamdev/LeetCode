class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        bool vis[n+10][m+10];
        memset(vis,0,sizeof(vis));
        for(int i = 0;i<n;++i){
            for(int j =0;j<m;++j){
                if(matrix[i][j] == 0){
                    vis[i][j] =true;
                }
            }
        }
        
         for(int i = 0;i<n;++i){
             int x= i;
            for(int j =0;j<m;++j){
                int y = j;
                if(matrix[i][j] == 0 && vis[i][j]){
                    for(int k=0;k<m;++k){
                        matrix[i][k] = 0;
                    }
                     for(int k=0;k<n;++k){
                        matrix[k][j] = 0;
                    }
                }
            }
        }
    }
};