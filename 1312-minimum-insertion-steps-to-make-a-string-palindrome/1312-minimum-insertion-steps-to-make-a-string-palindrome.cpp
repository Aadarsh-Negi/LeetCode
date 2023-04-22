int const N = 555;
int dp[N][N];
class Solution {
public:
    int solve(string &s,int i,int j){
        if(i>=j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int temp = INT_MAX;
        if(s[i] == s[j]) temp = solve(s,i+1,j-1);
        temp = min(temp,1+solve(s,i+1,j));
        temp = min(temp,1+solve(s,i,j-1));
        return dp[i][j] = temp;
        
    }
    int minInsertions(string s) {
        memset(dp,-1,sizeof(dp));
        return solve(s,0,s.size()-1);
    }
};