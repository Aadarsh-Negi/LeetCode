int dp[1003];
class Solution {
public:
    int solve(vector<int> &ar,int i){
        if(i>=ar.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        
        return dp[i] = ar[i] + min(solve(ar,i+1),solve(ar,i+2));
    
    }
    int minCostClimbingStairs(vector<int>& ar) {
        memset(dp,-1,sizeof(dp));
        
        return min(solve(ar,0),solve(ar,1));
        
    }
};