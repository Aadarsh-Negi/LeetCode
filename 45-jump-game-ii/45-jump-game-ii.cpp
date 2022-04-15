int dp[9999];
class Solution {
public:
    int solve(int i,vector<int> &nums){
        if(i>=nums.size()-1) return 0;
        if(dp[i]!=-1) return dp[i];
        int temp = INT_MAX/2;
        for(int j=1;j<=nums[i];j++){
            temp = min(1+solve(i+j,nums),temp);
        }
        return dp[i]=temp;
        
    }
    int jump(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(0,nums);
    }
};