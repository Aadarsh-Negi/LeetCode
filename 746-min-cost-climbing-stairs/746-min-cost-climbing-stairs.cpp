// int dp[1003];
class Solution {
public:
    int solve(vector<int> &ar,int i,int *dp){
        if(i>=ar.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        return dp[i] = ar[i] + min(solve(ar,i+1,dp),solve(ar,i+2,dp));
    }
    int minCostClimbingStairs(vector<int>& ar) {
        int dp[ar.size()+1];
        memset(dp,-1,sizeof(dp));
        return min(solve(ar,0,dp),solve(ar,1,dp));
        
    }
};