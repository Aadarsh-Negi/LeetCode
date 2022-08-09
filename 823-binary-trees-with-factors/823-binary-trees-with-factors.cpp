int const mod = 1e9 + 7;
int dp[1005];
class Solution {
public:
    map<int,int> avl;
    int solve(int i,vector<int> &ar){
        if(dp[i]!=-1) return dp[i];
        long long temp=1;
        for(int j=0;j<ar.size();j++){
            if(ar[i]%ar[j]==0){
                int s2 = ar[i]/ar[j];
                if(avl.count(s2)){
                    temp+=1LL*solve(j,ar)*solve(avl[s2],ar);
                    temp%=mod;
                }
            }
        }
        return dp[i] = temp;
        
    }
    
    int numFactoredBinaryTrees(vector<int>& ar) {
        memset(dp,-1,sizeof(dp));
        int idx=0;
        for(int &i:ar) avl[i] = idx++;
        for(int i=0;i<ar.size();i++)
            solve(i,ar);
        
        long long ans=0;
        for(int i=0;i<=ar.size();i++){
            if(dp[i]!=-1) ans+=dp[i];
            ans%=mod;
        }
        return ans;
    }
};