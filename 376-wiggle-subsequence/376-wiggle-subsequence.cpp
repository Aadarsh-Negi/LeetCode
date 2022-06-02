int dp[1005][1005][3];
class Solution {
public:
    vector<int> nums;
    int solve(int i,int val,int fl){
        if(i>=nums.size()) return 0;
        
        if(val==-1){
            return max(solve(i+1,nums[i],fl),solve(i+1,val,fl));
        }
        
        if(dp[i][val][fl]!=-1) return dp[i][val][fl];
        int temp=0;
        
        if(fl){ // neg diff
            
            if(val-nums[i]<0) temp = 1 + solve(i+1,nums[i],fl^1);
            temp = max(temp,solve(i+1,val,fl));
            
            
        }else{
            if(val-nums[i]>0) temp = 1 + solve(i+1,nums[i],fl^1);
            temp = max(temp,solve(i+1,val,fl));
        }
        return dp[i][val][fl]=temp;
        
    }
    int wiggleMaxLength(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        this->nums = nums;
        return max(solve(0,-1,0),solve(0,-1,1))+1;
        
    }
};