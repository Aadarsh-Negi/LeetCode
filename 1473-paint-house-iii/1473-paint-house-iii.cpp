int dp[103][103][103];
class Solution {
public:
    int minCost(vector<int>& h, vector<vector<int>>& cost, int m, int n, int t) {
        memset(dp,-1,sizeof(dp));
        function<long long(int,int,int)> solve = [&](int tar,int i,int prev){
            if(i==h.size() && tar==1) return (long long)0;
            if(i>=h.size() || tar<=0) return (long long)INT_MAX;
            if(dp[i][tar][prev]!=-1) return (long long)dp[i][tar][prev];
            long long temp=INT_MAX;
            if(h[i]!=0){
                if(i-1>=0)
                    temp = solve(tar - (h[i] != prev),i+1,h[i]);
                else temp = solve(tar,i+1,h[i]);
            }else{
                for(int j=1;j<=n;j++){
                    if(i-1>=0)
                        temp = min(temp,cost[i][j-1] + solve(tar - (j != prev),i+1,j));
                    else temp = min(temp,cost[i][j-1] + solve(tar,i+1,j));
                    
                }
            }
            
            dp[i][tar][prev] = temp;
            return temp;
        };
        int ans = solve(t,0,0);
        return ans==INT_MAX ? -1 : ans;
    }
};