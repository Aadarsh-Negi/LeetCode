class Solution {
public:
    int solve(int i,int j,vector<vector<int>> &m,vector<vector<int>> &dp){
        // if(i<0 || j<0 || i>=m.size() || j>=m[0].size()) return INT_MAX/2;
        if(dp[i][j]!=-1) return dp[i][j];
        int x=1;
        if(i+1<m.size() && m[i+1][j]>m[i][j]) x=1+solve(i+1,j,m,dp);
        if(j+1<m[0].size() && m[i][j+1]>m[i][j]) x=max(x,1+solve(i,j+1,m,dp));
        if(i-1>=0 && m[i-1][j]>m[i][j]) x=max(x,1+solve(i-1,j,m,dp));
        if(j-1>=0 && m[i][j-1]>m[i][j]) x=max(x,1+solve(i,j-1,m,dp));
        return dp[i][j]=x;
    }
    int longestIncreasingPath(vector<vector<int>>& mm) {
        vector<vector<int>> dp(202,vector<int>(202,-1));
        int ans=1;
        for(int i=0;i<mm.size();i++){
            for(int j=0;j<mm[0].size();j++){
                ans=max(ans,solve(i,j,mm,dp));
            }
        }
        return ans;   
    }
};