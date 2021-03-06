class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i,int j,string &s1,string &s2){
        if(i==s1.size() || j==s2.size()) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        int temp=0;
        if(s1[i]==s2[j]) temp = 1+solve(i+1,j+1,s1,s2);
        else temp = max({temp,solve(i+1,j,s1,s2),solve(i,j+1,s1,s2)});
        return dp[i][j]=temp;
    }
    int minDistance(string s1, string s2) {
        dp.resize(s1.size()+2,vector<int>(s2.size()+2,-1));
        
//         for(int i=1;i<=s1.size();i++){
//             for(int j=1;j<=s2.size();j++){
//                 if(s1[i-1]==s2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
//                  dp[i][j] = max({dp[i][j],dp[i-1][j],dp[i][j-1]});
//             }
//         }
        
        int ans = solve(0,0,s1,s2);
        ans = s1.size() + s2.size() - 2*ans;
        return ans;
        
    }
};