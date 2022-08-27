long long dp[100004][2];
class Solution {
public:
    
    long long solve(vector<int> &ar,int i,int f){
        if(i>=ar.size()) return 0;
        
        if(dp[i][f]!=-1) return dp[i][f];
        
        long long temp = (f ? ar[i] : -ar[i]) + solve(ar,i+1,f^1);
        temp = max(temp,solve(ar,i+1,f));
        return dp[i][f] = temp;
    }
    
    long long maxAlternatingSum(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(nums,0,1);
    }
};