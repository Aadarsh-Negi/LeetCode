
class Solution {
public:
    vector<int> dp;
    int deleteAndEarn(vector<int>& nums) {
        dp.resize(*max_element(nums.begin(),nums.end())+1,0);
        for(int &i:nums) dp[i]+=i;
        for(int i=2;i<dp.size();i++)
            dp[i] = max(dp[i-1],dp[i] + dp[i-2]);    
        
        
        return dp.back();
    }
};