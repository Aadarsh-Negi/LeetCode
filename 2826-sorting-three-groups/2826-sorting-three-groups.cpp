int dp[105][6];
class Solution {
public:
    int solve(vector<int> &nums,int prev,int i=0){
        if(i>=nums.size()) return 0;
        if(dp[i][prev]!=-1) return dp[i][prev];
        int cur = nums[i];
        int temp = INT_MAX/2;
        if(prev==1){
            if(cur==2){
                temp = solve(nums,cur,i+1);
                temp = min(temp,1+solve(nums,1,i+1));
            }else if(cur==3){
                temp = solve(nums,cur,i+1);
                temp = min(temp,1+solve(nums,1,i+1));
                temp = min(temp,1+solve(nums,2,i+1));
            }else{
                temp = solve(nums,cur,i+1);
            }
        }else if(prev==2){
            if(cur==1){
                temp = 1+solve(nums,2,i+1);
                temp = min(temp,1+solve(nums,3,i+1));
            }else if(cur==3){
                temp = solve(nums,cur,i+1);
                temp = min(temp,1+solve(nums,2,i+1));
            }else{
                temp = solve(nums,cur,i+1);
            }
        }else{
            if(cur==2){
                temp = min(temp,1+solve(nums,3,i+1));
            }else if(cur==3){
                temp = solve(nums,cur,i+1);
            }else{
                temp = 1+solve(nums,3,i+1);
            }
        }
        
        return dp[i][prev] = temp;
        
        
    }
    int minimumOperations(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return min({solve(nums,1),solve(nums,2),solve(nums,3)});
    }
};