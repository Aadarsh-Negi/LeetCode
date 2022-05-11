int dp[100][100];
class Solution {
public:
    int solve(int n,int i){
        if(n==0) return 1;
        if(i>=5) return 0;
        
        if(dp[n][i]!=-1) return dp[n][i];
        
        int res=0;
        for(int j=i;j<5;j++){
            res+=solve(n-1,j);
        }
        return dp[n][i] = res;
    }
    int countVowelStrings(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(n,0);
    }
};