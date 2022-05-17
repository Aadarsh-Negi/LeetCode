
class Solution {
public:
    int n;
    map<string,int> dp;
    int solve(vector<int> &c,int i,int ss){
        if(ss==0) return 1;
        if(i>=c.size() || ss<0) return 0;
        string kx = to_string(i) + "|" + to_string(ss);
        if(dp.count(kx)) return dp[kx];
        return dp[kx] = solve(c,i,ss-c[i]) + solve(c,i+1,ss);
    }
    int change(int sum, vector<int>& coins) {
        n=coins.size();
        // memset(dp,-1,sizeof(dp));
        return solve(coins,0,sum);
   
    }
};