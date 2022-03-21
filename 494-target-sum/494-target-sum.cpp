class Solution {
public:
    int solve(int i,int tar,vector<int> &ar,map<pair<int,int>,int> &dp){
       
        
        if(i>=ar.size()){
            return !tar;
        }
        
        if(dp.count({i,tar})) return dp[{i,tar}];
        
        
        return dp[{i,tar}] = solve(i+1,tar-ar[i],ar,dp) + solve(i+1,tar+ar[i],ar,dp);
        
        
        
        
    }
    int findTargetSumWays(vector<int>& nums, int tar) {
        // int n = nums.size();
        map<pair<int,int>,int> dp;
        
        
        return solve(0,tar,nums,dp);
    }
};