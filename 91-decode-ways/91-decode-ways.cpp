int dp[205];
class Solution {
public:
    set<string> avl;
    int solve(int i,string &s){
        if(i>=s.size()) return 1;
        
        if(dp[i]!=-1) return dp[i];
        
        string temp;
        int ans=0;
        for(int j=i;j<min(j+2,(int)s.size());j++){
            temp+=s[j];
            if(avl.count(temp)){
                ans+=solve(j+1,s);
            }
        }
        return dp[i] = ans;
        
    }
    int numDecodings(string s) {
        memset(dp,-1,sizeof(dp));
        for(int i=1;i<=26;i++) avl.insert(to_string(i));
        return solve(0,s);
    }
};