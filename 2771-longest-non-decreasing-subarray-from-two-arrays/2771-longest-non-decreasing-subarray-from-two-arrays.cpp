int dp[100001][3];
class Solution {
public:
    int solve(vector<int> &a,vector<int> &b,int prev,int i = 0){
        if(i>=a.size()) return 0;
        if(dp[i][prev]!=-1) return dp[i][prev];
        int temp = 0;
        if(prev==2){
            temp = max(temp,1+solve(a,b,0,i+1));
            temp = max(temp,1+solve(a,b,1,i+1));
            temp = max(temp,solve(a,b,2,i+1));
        }else{
            if(a[i] >= (prev ? b[i-1] : a[i-1]))
                temp = max(temp,1+solve(a,b,0,i+1));
            if(b[i] >= (prev ? b[i-1] : a[i-1]))
                temp = max(temp,1+solve(a,b,1,i+1));
        }
        return dp[i][prev] = temp;
    }
    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
        memset(dp,-1,sizeof(dp));
        return solve(nums1,nums2,2);
    }
};