int dp[100015][1005];
class Solution {
public:
    
    int solve(vector<int> &ar,vector<int> &mult,int i,int k){
        if(k==mult.size()) return 0;
        if(dp[i][k]!=INT_MIN) return dp[i][k];
        int temp = INT_MIN;
        
        int j = (int)ar.size() - (k-i) - 1;
        
        temp = max(temp , ar[i]*mult[k] + solve(ar,mult,i+1,k+1));
        temp = max(temp , ar[j]*mult[k] + solve(ar,mult,i,k+1));
        // temp = max(temp , ar[i]*mult[k] + solve(ar,mult,i+1,k+1));
        
        
        return dp[i][k] = temp;
    }
    int maximumScore(vector<int>& ar, vector<int>& mult) {
        
        // memset(dp,-1,sizeof(dp));
        for(int i=0;i<=ar.size()+5;i++) for(int j=0;j<=mult.size()+2;j++) dp[i][j] = INT_MIN;
        return solve(ar,mult,0,0);
    }
};