class Solution {
public:
    bool makesquare(vector<int>& ar) {
        int n = ar.size();
        int ss=0;
        for(int &i:ar) ss+=i;
        
        if(ss%4) return false;
        
        ss/=4;
        
        
        vector<int> dp(1<<n,-1);
        dp[0] = 0;
        for(int i=0;i<(1<<n);i++){
            
            if(dp[i]==-1) continue;
            
            for(int j=0;j<n;j++){
                if(i&(1<<j));
                else if(dp[i] + ar[j] > ss);
                else{
                    dp[i|(1<<j)] = (dp[i] + ar[j])%ss;
                }
            }
            
        }
        
        
        return dp[(1<<n)-1]==0;
        
        
    }
};