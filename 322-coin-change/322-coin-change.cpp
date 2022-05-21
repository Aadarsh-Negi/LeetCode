
class Solution {
public:
    int solve(int i,int ss,vector<int> &ar,vector<vector<int>> &dp){
        if(ss==0) return 0;
        if(i>=ar.size() || ss<0) return INT_MAX/2;
        if(dp[ss][i]!=-1) return dp[ss][i];
        int temp=INT_MAX;
        for(int j=i;j<ar.size();j++){
            temp = min(temp,1+solve(j,ss-ar[j],ar,dp));
            temp = min(temp,solve(j+1,ss,ar,dp));
        }
        return dp[ss][i]=temp;
    }
    int coinChange(vector<int>& ar, int ss) {
        vector<vector<int>> dp(ss+1,vector<int>(ar.size()+1,-1));
        // memset(dp,-1,sizeof(dp));
        int ans = solve(0,ss,ar,dp);
        return ans>=INT_MAX/2?-1:ans;
    }
};