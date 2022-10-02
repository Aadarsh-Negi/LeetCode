int dp[1005][35];
int const mod = 1e9 + 7;
class Solution {
public:
    int solve(int n,int &k,int tar){
        if(tar==0 && n==0) return 1;
        if(tar<=0 || n==0) return 0;
        
        if(dp[tar][n]!=-1) return dp[tar][n];
        long long temp=0;
        
        for(int i=1;i<=k;i++){
            temp+=solve(n-1,k,tar-i);
            temp%=mod;
        }
        return dp[tar][n] = temp;
    }
    int numRollsToTarget(int n, int k, int tar) {
        memset(dp,-1,sizeof(dp));
        return solve(n,k,tar);
    }
};