int dp[2004];
class Solution {
public:
    bool ok(const string &s,int i,int j){
        while(i<j) if(s[i++]!=s[j--]) return 0;
        return 1;
    }
    int solve(const string &s,int i,int j){
        if(i>=j || ok(s,i,j)) return 0;
        if(dp[i]!=-1) return dp[i];
        int temp = INT_MAX/2;
        for(int k=i;k<j;k++){
            if(ok(s,i,k))
                temp = min(temp,1+solve(s,k+1,j));
        }
        return dp[i] = temp;
    }
    int minCut(string s) {
        memset(dp,-1,sizeof(dp));
        return solve(s,0,s.size()-1);
    }
};