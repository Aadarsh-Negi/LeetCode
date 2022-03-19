class Solution {
public:
    vector<int> dp;
    bool solve(int i,vector<int> &nums){
        if(i>=nums.size()-1) return 1;
        
        if(dp[i]!=-1) return dp[i];
        
        for(int j=nums[i];j>=1;j--){
            dp[i] = solve(i+j,nums);
            if(dp[i]==1) return dp[i];
        }
        return 0;
        
    }
    
    
    bool canJump(vector<int>& nums) {
        // if(nums.size()==1) return 1;
        dp.resize(nums.size()+1);
        fill(dp.begin(),dp.end(),-1);
        return solve(0,nums);
    }
};