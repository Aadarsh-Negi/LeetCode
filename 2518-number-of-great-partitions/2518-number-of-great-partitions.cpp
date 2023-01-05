int const N = 1e3 + 33;
int dp[N][N];
int const mod = 1e9 + 7;
class Solution {
public:
    int solve(vector<int> &ar,int k,int i,long c=0){
        if(c>=k) return 0;
        if(i>=ar.size()) return 1;
       
        if(dp[c][i]!=-1) return dp[c][i];
        
        long temp = solve(ar,k,i+1,c);
        temp%=mod;
        temp+=solve(ar,k,i+1,c+ar[i]);
        temp%=mod;
        return dp[c][i] = temp;
        
    }
    int countPartitions(vector<int>& ar, int k) {
        memset(dp,-1,sizeof(dp));
        long ttl=1;
        long long sum=0;
        for(int i=0;i<ar.size();i++) {ttl*=2; ttl%=mod; sum+=ar[i];}
        if(sum < 2*k) return 0;
        long res = solve(ar,k,0)*2;
        res%=mod;
        ttl-=res;
        ttl+=mod;
        ttl%=mod;
        return ttl;
    }
};