int dp[1001][1001];
int const mod = 1e9 + 7;
#define ll long long
class Solution {
public:
    Solution(){
        memset(dp,-1,sizeof(dp));
    }
    int kInversePairs(int n, int k) {
        if(n==0) return 0;
        if(k==0) return 1;
        
        if(dp[n][k]!=-1) return dp[n][k];
        
        ll temp=0;
        for(int i=0;i<min(k+1,n);i++){
            temp+=kInversePairs(n-1,k-i);
            temp%=mod;
        }
        return dp[n][k]=temp;
    }
};