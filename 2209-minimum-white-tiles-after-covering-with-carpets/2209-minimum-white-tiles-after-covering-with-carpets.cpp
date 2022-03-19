class Solution {
public:
    vector<int> pref;
    vector<vector<int>> dp;
    int n;
    int ll;
    int solve(string &fl,int nm,int i){
        if(i>=n) return 0;
        
        if(nm==0) return pref[n] - pref[i];
        
        if(dp[i][nm]!=-1) return dp[i][nm];
        
        return dp[i][nm] = min(solve(fl,nm-1,i+ll),(fl[i]=='1') + solve(fl,nm,i+1));
    }
    
    
    int minimumWhiteTiles(string &fl, int nm, int len) {
        n  = fl.size();
        ll=len;
        // int ttl = nm*len;
        // if(ttl>=n) return 0;
        pref.resize(n+2);
        
        pref[0]=0;
        for(int i=1;i<=n;i++) pref[i] = (fl[i-1]=='1') + pref[i-1];
        
        dp.resize(n+3);
        for(int i=0;i<=n+1;i++){
            dp[i].resize(nm+2);
            fill(dp[i].begin(),dp[i].end(),-1);
        }
        
        return solve(fl,nm,0);
        
    }
};