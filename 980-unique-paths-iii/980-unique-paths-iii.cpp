class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& gg) {
        int free=0;
        int n = gg.size();
        int m = gg[0].size();
        
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                free+=(gg[i][j]==0);
        
        int ans=0;
        
       auto solve = [&](auto && solve,int i,int j,int free){
            if(i<0 || j<0 || i>=n || j>=m || gg[i][j]==3 || gg[i][j]==-1) return;
            if(gg[i][j]==2){
                if(free==0) ans++;
                return;
            }
            
            gg[i][j] = 3;
            solve(solve,i+1,j,free-1);
            solve(solve,i,j+1,free-1);
            solve(solve,i-1,j,free-1);
            solve(solve,i,j-1,free-1);
            gg[i][j] = 1;
            
        };
        
        
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(gg[i][j]==1){ 
                    // cout<<i<<" "<<j<<"\n";
                    solve(solve,i,j,free+1); 
                    return ans;
                }
        
        return ans;
    }
};