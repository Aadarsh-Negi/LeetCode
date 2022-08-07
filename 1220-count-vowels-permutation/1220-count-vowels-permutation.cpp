int mod = 1e9 + 7;
int const N = 2e4 + 10;
int dp[28][N];
class Solution {
public:
    int solve(char c,int n){
        if(n==0) return 1;
        if(dp[c-'a'][n]!=-1) return dp[c-'a'][n];
        long long temp=0;
        if(c=='a'){
            temp+=solve('e',n-1);
            temp%=mod;
        }else if(c=='e'){
            temp+=solve('a',n-1);
            temp%=mod;
            temp+=solve('i',n-1);
            temp%=mod;
        }else if(c=='i'){
            temp+=solve('a',n-1);
            temp%=mod;
            temp+=solve('e',n-1);
            temp%=mod;
            temp+=solve('o',n-1);
            temp%=mod;
            temp+=solve('u',n-1);
            temp%=mod;
        }else if(c=='o'){
            temp+=solve('i',n-1);
            temp%=mod;
            temp+=solve('u',n-1);
            temp%=mod;
        }else{
            temp+=solve('a',n-1);
            temp%=mod;
        }
        return dp[c-'a'][n] = temp;
    }
    int countVowelPermutation(int n) {
        memset(dp,-1,sizeof(dp));
        int ans = solve('a',n-1);
        ans%=mod;
        ans+=solve('e',n-1);
        ans%=mod;
        ans+=solve('i',n-1);
        ans%=mod;
        ans+=solve('o',n-1);
        ans%=mod;
        ans+=solve('u',n-1);
        ans%=mod;
        return ans;
        
    }
};