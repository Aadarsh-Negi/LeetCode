class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& cc) {
          vector<vector<int>> adj(n);
        for(vector<int> &it:cc){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> dis(n,-1);
        vector<int> low(n,-1);
        int timer = 0;
        vector<vector<int>> ans;
        function<void(int,int)> dfs = [&](int u,int p){
            dis[u] = low[u] = timer++;
            
            for(int j:adj[u]){
                if(j==p) continue;
                if(dis[j]==-1){
                    dfs(j,u);
                    low[u] = min(low[u],low[j]);
                    
                    if(low[j]> dis[u]) ans.push_back({u,j});
                    
                }else{
                   low[u] = min(low[u],dis[j]);
                }
            }
        };
        dfs(0,-1);
        return ans;
    }
};