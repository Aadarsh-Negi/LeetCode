class Solution {
public:
    int uniquePaths(int m, int n) {
        int grid[m+2][n+2];
       
        
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(i==1){
                    grid[i][j]=1;
                }else if(j==1){
                    grid[i][j]=1;
                }else{
                    grid[i][j]=(grid[i-1][j]+grid[i][j-1]);
                }
                // cout<<grid[i][j]<<" ";
            }
            // cout<<"\n";
        }
        
        return grid[m][n];
        
    }
};