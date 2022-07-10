int dp[1003];
class Solution {
public:
    int minCostClimbingStairs(vector<int>& ar) {
        memset(dp,0,sizeof(dp));
        
        for(int i=2;i<=ar.size();i++){
            dp[i] = min(dp[i-1] + ar[i-1],dp[i-2] + ar[i-2]);
        }
        return dp[ar.size()];
        
    }
};