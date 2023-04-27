int const mod = 1e9 + 7;
int const N = 1e5 + 55;
int dp[N];
class Solution {
public:
    int solve(string &s,int k,int i=0){
        if(i>=s.size()) return 1;
        if(dp[i]!=-1) return dp[i];
        long long cur = 0;
        long long temp = 0;
        for(int j=i;j<s.size();j++){
            cur*=10;
            cur+=(s[j] - '0');
            if(cur>=1 && cur<=k){
                temp+=solve(s,k,j+1);
                temp%=mod;
            }else break;
        }
        return dp[i] = temp;
    }
    int numberOfArrays(string s, int k) {
        memset(dp,-1,sizeof(dp));
        return solve(s,k);
    }
};