int dp[55][55][55];
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
int mod = 1e9+7;
class Solution {
public:
    int solve(int &n,int &m,int k,int i,int j){
        if(i>=n || j>=m || i<0 || j<0) return 1;
        if(k==0) return 0;
        
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        
        long long temp=0;
        for(int l=0;l<4;l++){
            temp+=solve(n,m,k-1,i+dx[l],j+dy[l]);
            temp%=mod;
        }
        return dp[i][j][k] = temp;
    }
    int findPaths(int m, int n, int k, int s, int c) {
        memset(dp,-1,sizeof(dp));
        return  solve(m,n,k,s,c);
    }
};