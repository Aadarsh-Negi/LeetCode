class Solution {
public:
    
    void dfs(int u,int par,vector<vector<int>> &gp,vector<vector<int>> &ans){
        
        for(int i:gp[u]){
            if(ans[i].size()==0 || par!=ans[i].back()){
                ans[i].push_back(par);
                dfs(i,par,gp,ans);
            }
        }
    }
    
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> ans(n);
        
        vector<vector<int>> gp(n);
        for(auto it:edges){
            gp[it[0]].push_back(it[1]);
        }
        
        
        for(int i=0;i<n;i++){
            dfs(i,i,gp,ans);
        }
        
        return ans;
        
    }
};