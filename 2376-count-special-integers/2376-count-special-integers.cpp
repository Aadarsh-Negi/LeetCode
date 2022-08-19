int dp[14][5555][2];
class Solution {
public:
    string mx;
    int solve(int i,int fl=0,int ttl=0){
        if(i>=mx.size()) return ttl!=0;
        
        if(dp[i][ttl][fl]!=-1) return dp[i][ttl][fl];
        
        int temp=0;
        for(int k=0;k<10;k++){
            int v = mx[i] - '0';
            if((1<<k)&ttl) continue;
            int a = (ttl == 0 && k == 0 ? ttl : (ttl | (1 << k)));
            if(fl){
                temp+=solve(i+1,fl,a);
            }else if(v>=k) temp+=solve(i+1,v>k,a);
        }
        return dp[i][ttl][fl] = temp;
        
    }
    int countSpecialNumbers(int n) {
        mx = to_string(n);
        memset(dp,-1,sizeof(dp));
        return solve(0);
    }
};