// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
    public:
    int ans;
    int solve(int i,int j,string &s,string &s2,vector<vector<int>> &dp){
        if(i>=s.size() || j>=s2.size()) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        solve(i+1,j,s,s2,dp);
        solve(i,j+1,s,s2,dp);
        
        if(s[i]==s2[j]){
             dp[i][j] = 1+solve(i+1,j+1,s,s2,dp);
             
             ans=max(ans,dp[i][j]);
             return dp[i][j];
        }
        return dp[i][j] = 0;
   
        
    }
    
    
    int longestCommonSubstr (string S1, string S2,int n,int m)
    {
        vector<vector<int>> dp(1002,vector<int>(1002,-1));
        ans=0;
        solve(0,0,S1,S2,dp);
        return ans;
        // your code here
    }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends