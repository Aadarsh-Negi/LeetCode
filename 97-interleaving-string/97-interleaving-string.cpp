int dp[103][103][203];
class Solution {
public:
    bool solve(string &a,string &b,string &c,int i=0,int j=0,int k=0){
        if(i==a.size() && j==b.size() && k==c.size()) return 1;
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        
        int temp = 0;
        if(i<a.size() && a[i] == c[k]) temp|=solve(a,b,c,i+1,j,k+1);
        if(j<b.size() && b[j] == c[k]) temp|=solve(a,b,c,i,j+1,k+1);
        return dp[i][j][k] = temp;
    }
    bool isInterleave(string &s1, string &s2, string &s3) {
       memset(dp,-1,sizeof(dp));
       return solve(s1,s2,s3);
    }
};