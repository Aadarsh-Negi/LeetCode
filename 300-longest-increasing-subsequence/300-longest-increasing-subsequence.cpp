int dp[2600];
class Solution {
public:
    
    int solve(int i,vector<int> &ar){
        if(i==ar.size()) return 0;
        
        if(i==-1){
            int tx = -1;
            for(int k=0;k<ar.size();k++){
                tx = max(tx,2+solve(k,ar));
            }
            return tx;
        }
        if(dp[i]!=-1) return dp[i];
        int temp = -1;
        for(int j=i+1;j<ar.size();j++){
            if(ar[j]>ar[i]){
                temp = max(temp,1+solve(j,ar));
            }
        }
        
        
        return dp[i] = temp;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        // ans=-1;
        return solve(-1,nums);
        // return ans;
    }
};