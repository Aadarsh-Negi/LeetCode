
class Solution {
public:
//     int solve(vector<int> &ar,int tar){
//         if(tar==0) return 1;
//         if(dp[tar]!=-1) return dp[tar];
        
//         int temp=0;
//         for(int i=0;i<ar.size();i++){
//             if(ar[i] <= tar) temp+=solve(ar,tar-ar[i]);
//         }
//         return dp[tar] = temp;
//     }
    int combinationSum4(vector<int>& ar, int target) {
        unsigned int dp[target+1];
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        
        for(int i=1;i<=target;i++)
            for(int &j:ar)
                if(i>=j) dp[i]+=dp[i-j];
        
        
        
        
        return dp[target];
    }
};