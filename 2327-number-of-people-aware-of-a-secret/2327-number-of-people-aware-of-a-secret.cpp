class Solution {
public:
    
    int n;
    int d,f;
    vector<int> dp;
    int const mod = 1e9 + 7;
    int solve(int i=1){
        if(i>n) return 0;
        if(dp[i]!=-1) return dp[i];
        long long temp=0;
        for(int j=i+d;j<min(n+1,i+f);j++){
            temp+=1+solve(j);
            temp%=mod;
        }
        if(i+f<=n)
            temp--;
        temp+=mod;
        temp%=mod;
        
        return dp[i] = temp;
    }
    
    int peopleAwareOfSecret(int n, int d, int f) {
    this->n = n;
    this->d = d;
    this->f = f;
        dp.resize(n+10,-1);
        return solve()+1;
    }
};