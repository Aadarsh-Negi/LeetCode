int dp[1003][1003];
class Solution {
public:
    int solve(string &s,string &t,int i=0,int j=0){
        if(j==t.size()) return 1;
        if(i==s.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        
        int temp = 0;
        if(s[i]==t[j])
            temp += solve(s,t,i+1,j+1);
        temp+=solve(s,t,i+1,j);
        return dp[i][j] = temp;
    }
    int numDistinct(string &s, string &t) {
        memset(dp,-1,sizeof(dp));
        return solve(s,t);
    }
};