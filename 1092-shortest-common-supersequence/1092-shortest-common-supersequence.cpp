class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        int dp[n+1][m+1];
        memset(dp,0,sizeof(dp));
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        
        string lcs;
        
        int i = n;
        int j = m;
        
        while(i>0 && j>0){
            if(s1[i-1]==s2[j-1]){
                lcs+=s1[i-1];
                i--;
                j--;
            }else if(dp[i-1][j] > dp[i][j-1]) i--;
            else j--;
        }
        reverse(lcs.begin(),lcs.end());
       
        string ans;
        i=0;
        j=0;
        int k=0;
       while(k<lcs.size()){
           while(lcs[k]!=s1[i]) ans+=s1[i++];
           while(lcs[k]!=s2[j]) ans+=s2[j++];
           ans+=lcs[k++];
           i++;
           j++;
       }
        while(i<n) ans+=s1[i++];
        while(j<m) ans+=s2[j++];
        
        return ans;
        
    }
};