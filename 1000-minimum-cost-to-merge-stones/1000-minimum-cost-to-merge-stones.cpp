long long dp[35][35];
long long pref[505];
class Solution {
public:
    
    int solve(int i,int j,int &k){
        if(i >= j)  return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int temp = INT_MAX;
        for(int l=i;l<j;l+=k-1){
            temp = min(temp,solve(i,l,k) + solve(l+1,j,k));
        }
        if((j-i)%(k-1) == 0) temp+=pref[j+1] - pref[i];
        return dp[i][j] = temp;
        
    }
    int mergeStones(vector<int>& stones, int k) {
        memset(dp,-1,sizeof(dp));
        memset(pref,0,sizeof(pref));
        for(int i=1;i<=stones.size();i++){
            pref[i]+=pref[i-1] + stones[i-1];
        }
        int ans = solve(0,stones.size()-1,k); 
        return (ans==INT_MAX|(stones.size()-1)%(k-1))?-1:ans;
    }
};