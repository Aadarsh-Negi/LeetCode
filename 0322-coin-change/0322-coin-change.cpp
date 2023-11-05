class Solution {
public:
    int coinChange(vector<int>& coins, int x) {
        int dp[x+2];
        dp[0] = 0;
        for(int i=1;i<=x;i++){
            dp[i] = INT_MAX/2;
            for(int j:coins){
                if(i-j >= 0){
                    dp[i] = min(dp[i],dp[i-j]+1);
                }
            }
        }
        
        return dp[x] >= INT_MAX/2 ? -1 : dp[x];
    }
};
