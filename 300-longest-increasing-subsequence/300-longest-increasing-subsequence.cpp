int dp[2600];
class Solution {
public:
    int solve(int i,vector<int> &ar,int mn = INT_MIN){
        if(i==ar.size()) return 0;
        
        
        int temp = -1;
        if(ar[i]>mn){
            if(dp[i]==-1) dp[i] = 1+solve(i+1,ar,ar[i]);
            temp = dp[i];
        }
        temp = max(temp,solve(i+1,ar,mn));
        
        return temp;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        // ans=-1;
        return solve(0,nums);
        // return ans;
    }
};