int dp[103][103][23];
class Solution {
public:
    int minCost(vector<int>& h, vector<vector<int>>& cost, int m, int n, int t) {
        memset(dp,-1,sizeof(dp));
        function<long long(int,int,int)> solve = [&](int tar,int i,int prev){
            if(i==h.size() && tar==0) return (long long)0;
            if(i>=h.size() || tar<0) return (long long)INT_MAX;
            
            if(dp[i][tar][prev]!=-1) return (long long)dp[i][tar][prev];
            long long temp=INT_MAX;
      
                for(int j=1;j<=n;j++){
                    temp = min(temp,(h[i] ? 0 : cost[i][j-1]) + solve(tar - ((h[i] ? h[i] : j) != prev),i+1,h[i] ? h[i] : j));
                }
     
            dp[i][tar][prev] = temp;
            return temp;
        };
        int ans = solve(t,0,0);
        return ans==INT_MAX ? -1 : ans;
    }
};