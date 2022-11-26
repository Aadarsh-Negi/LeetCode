#define ll long long
int dp[10005][11][11][6];
int const mod = 1e9 + 7;
class Solution {
public:
    int n;
    string s;
    int solve(int i,int f,int se,int l){
        if(l==5) return 1;
        if(i>=n) return 0;
        if(dp[i][f][se][l]!=-1) return dp[i][f][se][l];
        ll tx=0;
        if(l==0){
            tx+=solve(i+1,s[i]-'0',se,l+1);
            tx%=mod;
        }else if(l==1){
            tx+=solve(i+1,f,s[i]-'0',l+1);
            tx%=mod;
        }else if(l==2){
            tx+=solve(i+1,f,se,l+1);
            tx%=mod;
        }else if(l==3){
            if(se==(s[i]-'0')){
                tx+=solve(i+1,f,se,l+1);
                tx%=mod;    
            }
        }else{
            if(f==(s[i]-'0')){
                tx+=solve(i+1,f,se,l+1);
                tx%=mod;    
            }
        }
        tx+=solve(i+1,f,se,l);
        tx%=mod;
        return dp[i][f][se][l] = tx;
        
    }
    int countPalindromes(string s) {
        this->s = s;
        n = s.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,0,0,0);
    }
};