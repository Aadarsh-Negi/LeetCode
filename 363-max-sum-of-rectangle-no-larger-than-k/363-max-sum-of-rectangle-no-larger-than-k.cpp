class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& mat, int K) {
        int n = mat.size();
        int m = mat[0].size();
        int pref[n+3][m+3];
        memset(pref,0,sizeof(pref));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                pref[i][j]=pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1] + mat[i-1][j-1];
            }
        }
        // cout<<k<<"\n\n";
        int ans=INT_MIN;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                for(int k=i;k<=n;k++){
                    for(int l=j;l<=m;l++){
                        int val = pref[k][l] - pref[k][j-1] - pref[i-1][l] + pref[i-1][j-1];
                        // cout<<" > "<<i<<" "<<j<<" "<<l<<" "<<k<<"\n";
                        if(val <= K) 
                            ans=max(ans,val);
                        // cout<<val <<" <> "<<ans<<"\n";
                    }
                }
            }
        }
        return ans;
        
    }
};