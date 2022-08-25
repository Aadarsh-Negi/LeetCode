int dp[105][10004];
class Solution {
public:
    int n,tx;
    
    int solve(vector<vector<int>> &mat,int i,int ttl=0){
        if(i>=n) return abs(tx - ttl);
            
        if(dp[i][ttl]!=-1) return dp[i][ttl];
        int temp = INT_MAX;
        for(int j=0;j<mat[i].size();j++){
            temp = min(temp,solve(mat,i+1,ttl+mat[i][j]));
            if(temp==0) break;
        }
        return dp[i][ttl] = temp;
    }
 
    
    int minimizeTheDifference(vector<vector<int>>& mat, int tar) {
        n=mat.size();
        tx=tar;
        memset(dp,-1,sizeof(dp));
        return solve(mat,0);

    }
};