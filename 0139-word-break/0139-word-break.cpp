int dp[305];
class Solution {
public:
    bool ok(string &a,string &b,int j){
        int i=0;
        while(i<a.size() && j<b.size()){
            if(a[i]!=b[j]) return 0;
            i++;
            j++;
        }
        return (i==a.size());
    }
    bool solve(string &s,vector<string> &ww,int i){
        if(i>=s.size()){
            return 1;
        }
        
        if(dp[i]!=-1) return dp[i];
        
        bool temp = 0;
        
        for(string &c:ww){
            if(ok(c,s,i)){
                temp|=solve(s,ww,i+c.size());
            }
        }
        return dp[i] = temp;
    }
    bool wordBreak(string s, vector<string>& wr) {
        memset(dp,-1,sizeof(dp));
        return solve(s,wr,0);
    }
};