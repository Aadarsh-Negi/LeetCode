int dp[105][105][105];
class Solution {
public:
    vector<vector<char>> gg;
    int n,m;
    bool solve(int i,int j,int open=0){
        if(i>=n || j>=m) return 0;
        
        if(gg[i][j]=='(') open++;
        else open--;
        
        if(open<0 || open>=101) return 0;
        
        if(i==n-1 && j==m-1) return open==0;
        
        if(dp[i][j][open]!=-1) return dp[i][j][open];
        
        return dp[i][j][open] = (solve(i+1,j,open) | solve(i,j+1,open));
    }
    
    bool hasValidPath(vector<vector<char>>& grid) {
        gg=grid;
        n=gg.size();
        m=gg[0].size();
        memset(dp,-1,sizeof(dp));
        return solve(0,0);
    }
};