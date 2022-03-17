class Solution {
public:
    
    void solve(vector<vector<int>> &ht,int i,int j,vector<vector<int>> &vis){
        if(vis[i][j]) return;
         vis[i][j]=1;
        if(i+1<ht.size() && ht[i+1][j]>=ht[i][j]) solve(ht,i+1,j,vis);
        if(j+1<ht[0].size() && ht[i][j+1]>=ht[i][j]) solve(ht,i,j+1,vis);
        if(i-1>=0 && ht[i-1][j]>=ht[i][j]) solve(ht,i-1,j,vis);
        if(j-1>=0 && ht[i][j-1]>=ht[i][j]) solve(ht,i,j-1,vis);
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& ht) {
        
        int n = ht.size();
        int m = ht[0].size();
        
        vector<vector<int>> pac(n,vector<int>(m,0));
        vector<vector<int>> atl(n,vector<int>(m,0));
        vector<vector<int>> ans;
        
        for(int i=0;i<m;i++){
            if(!pac[0][i]) solve(ht,0,i,pac);
        }
        for(int i=0;i<n;i++){
            if(!pac[i][0]) solve(ht,i,0,pac);
        }
        for(int i=0;i<n;i++){
            if(!atl[i][m-1]) solve(ht,i,m-1,atl);
        }
        for(int i=0;i<m;i++){
            if(!atl[n-1][i]) solve(ht,n-1,i,atl);
        }
        
        
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(pac[i][j] && atl[i][j]) ans.push_back({i,j});
        
        return ans;
        
        
        
    }
};