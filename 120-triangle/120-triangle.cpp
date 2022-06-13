class Solution {
public:
    
    int solve(vector<vector<int>>& tt,int i,int j,vector<vector<int>>& dp){
        if(i>=tt.size() || j>=tt[i].size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        
        return dp[i][j] = tt[i][j] + min(solve(tt,i+1,j+1,dp),solve(tt,i+1,j,dp));
    }
    
    int minimumTotal(vector<vector<int>>& tt) {
        int n=tt.size();
        vector<vector<int>> dp(n+3,vector<int>(n+3,-1));
        
        // return solve(tt,0,0,dp);
        
        // dp[0]=dp[1]=0;
        // dp[0]=0;
        // for(int i=1;i<=n;i++) dp[i] = tt[n-1][i-1];
        // for(int i=tt.size()-1;i>0;i--){
        //     for(int j=1;j<=i;j++){
        //         dp[j] = min(dp[j+1] + tt[i-1][j-1], dp[j] + tt[i-1][j-1]);  
        //     }
        // }
        return solve(tt,0,0,dp);
        
        // for(int i=0;i<=n;i++){
        //     for(int j=0;j<=n;j++){
        //         cout<<dp[i][j]<<" ";
        //     }cout<<"\n";
        // }
        // for(int i:dp) cout<<i<<" ";
        // cout<<"\n";
        // return dp[1];
        
        
        
        
        
    }
};