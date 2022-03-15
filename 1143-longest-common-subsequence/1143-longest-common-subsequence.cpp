class Solution{
    public:
    
    int solve(int i,int j,string &s,string &s2,vector<vector<int>> &dp){
        if(i>=s.size() || j>=s2.size()) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(s[i]==s2[j]){
            return dp[i][j] = max({1+solve(i+1,j+1,s,s2,dp),solve(i,j+1,s,s2,dp),solve(i+1,j,s,s2,dp)});
        }else return dp[i][j] = max({solve(i,j+1,s,s2,dp),solve(i+1,j,s,s2,dp)});
   
        
    }
    
    
    int longestCommonSubsequence (string S1, string S2)
    {
        vector<vector<int>> dp(1002,vector<int>(1002,-1));
        
        return solve(0,0,S1,S2,dp);
        // your code here
    }
};
