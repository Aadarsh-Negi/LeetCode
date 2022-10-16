int dp[305][15];
class Solution {
public:
    int solve(vector<int> &ar,int d,int i){
        int mx=-1;
        if(i>=ar.size()) return INT_MAX/2;
        if(d==0){
            for(int j=i;j<ar.size();j++) mx = max(mx,ar[j]);
            return mx;
        }
        
        if(dp[i][d]!=-1) return dp[i][d];
        int temp = INT_MAX;
        for(int j=i;j<ar.size();j++){
            mx = max(mx,ar[j]);
            temp = min(temp,mx + solve(ar,d-1,j+1));
        }
        return dp[i][d] = temp;
        
    }
    int minDifficulty(vector<int>& jb, int d) {
        memset(dp,-1,sizeof(dp));
        int ans = solve(jb,d-1,0);
        return ans>=INT_MAX/2 ? -1 : ans;
    }
};