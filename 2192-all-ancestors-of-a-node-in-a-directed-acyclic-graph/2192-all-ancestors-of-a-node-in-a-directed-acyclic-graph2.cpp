class Solution {
public:
    
    void dfs(int u,int par,vector<int> gp[],vector<set<int>> &ans,vector<int> &vis){
        if(u!=par){
            ans[u].insert(par);
        }
        vis[u]=1;
        for(int i:gp[u]) if(vis[i]!=1) dfs(i,par,gp,ans,vis);
    }
    
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<set<int>> ans(n);
        
        vector<int> gp[n+2];
        for(auto it:edges){
            gp[it[0]].push_back(it[1]);
        }
        
        
        for(int i=0;i<n;i++){
            vector<int> vis(n,0);
            dfs(i,i,gp,ans,vis);
        }
        
        vector<vector<int>> ans2;
        
        for(auto it:ans){
            vector<int> temp;
            
            for(int i:it) temp.push_back(i);
            ans2.push_back(temp);
        }
        
        return ans2;
        
    }
};
