class Solution {
public:
    int n,m;
    vector<vector<int>> cnt;
    vector<vector<int>> g;
    int const mod = 1e9 + 7;
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,-1,1};
    int dfs(int i,int j){
        
        if(cnt[i][j]!=-1) return cnt[i][j];
        int t=0;
        for(int k=0;k<4;k++){
            int ix = i + dx[k];
            int jx = j + dy[k];
            if(ix<0 || jx<0 || ix>=n || jx>=m) continue;
            
            if(g[i][j] < g[ix][jx])
                t+=1+dfs(ix,jx);
            t%=mod;
        }
        return cnt[i][j] = t;
    }
    int countPaths(vector<vector<int>>& g2) {
        g=g2;
        n = g.size();
        m = g[0].size();
        cnt.resize(n,vector<int>(m,-1));
        
        long long ans=n*m;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++){
                 for(int k=0;k<4;k++){
                    int ix = i + dx[k];
                    int jx = j + dy[k];
                    if(ix<0 || jx<0 || ix>=n || jx>=m) continue;
                    if(g[ix][jx] > g[i][j])
                        ans+=1+dfs(ix,jx),ans%=mod;
                    
                }
            }
                  
        }
        return ans;
    }
};