
class Solution {
public:
    int solve(int ss,vector<int> &ar,int *dp){
        if(ss==0) return 0;
        if(ss<0) return INT_MAX/2;
        if(dp[ss]!=-1) return dp[ss];
        int temp=INT_MAX;
        for(int j=0;j<ar.size();j++){
            temp = min(temp,1+solve(ss-ar[j],ar,dp));
        }
        return dp[ss]=temp;
    }
    int coinChange(vector<int>& ar, int ss) {
        int dp[ss+1];
        memset(dp,-1,sizeof(dp));
        int ans = solve(ss,ar,dp);
        return ans>=INT_MAX/2?-1:ans;
    }
};