int dp[105][10004];
int ar[105][105];
class Solution {
public:
    int n,tx;
    int m;
    int solve(int i,int ttl=0){
        if(i>=n) return abs(tx - ttl);
            
        if(dp[i][ttl]!=-1) return dp[i][ttl];
        int temp = INT_MAX;
        for(int j=0;j<m;j++){
            temp = min(temp,solve(i+1,ttl+ar[i][j]));
        }
        return dp[i][ttl] = temp;
    }
 
    
    int minimizeTheDifference(vector<vector<int>>& mat, int tar) {
        n=mat.size();
        m = mat[0].size();
        for(int i=0;i<n;i++)
            for(int j=0;j<mat[i].size();j++) ar[i][j] = mat[i][j];
        tx=tar;
        memset(dp,-1,sizeof(dp));
        return solve(0);

    }
};