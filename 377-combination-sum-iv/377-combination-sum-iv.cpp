int dp[1004];
class Solution {
public:
    int solve(vector<int> &ar,int tar){
        if(tar==0) return 1;
        if(dp[tar]!=-1) return dp[tar];
        
        int temp=0;
        for(int i=0;i<ar.size();i++){
            if(ar[i] <= tar) temp+=solve(ar,tar-ar[i]);
        }
        return dp[tar] = temp;
    }
    int combinationSum4(vector<int>& ar, int target) {
        memset(dp,-1,sizeof(dp));
        return solve(ar,target);
    }
};