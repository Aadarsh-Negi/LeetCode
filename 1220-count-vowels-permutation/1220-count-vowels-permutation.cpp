int mod = 1e9 + 7;
int const N = 2e4 + 10;
int dp[28][N];
class Solution {
public:
    string vowel;
   vector<string> req;
    int solve(char c,int n){
        if(n==0) return 1;
        if(dp[c-'a'][n]!=-1) return dp[c-'a'][n];
        long long temp=0;
        
        for(char &cx:req[c-'a']){
            temp+=solve(cx,n-1);
            temp%=mod;
        }
        
        
        return dp[c-'a'][n] = temp;
    }
    int countVowelPermutation(int n) {
        memset(dp,-1,sizeof(dp));
        int ans = 0;
        vowel = "aeiou";
        req.resize(28);
        req['a' - 'a'] = "e";
        req['e' - 'a'] = "ai";
        req['i' -'a'] = "aeou";
        req['o'-'a'] = "iu";
        req['u'-'a'] = 'a';
        for(char &c:vowel){
            ans+=solve(c,n-1);
            ans%=mod;
        }
        
        return ans;
        
    }
};