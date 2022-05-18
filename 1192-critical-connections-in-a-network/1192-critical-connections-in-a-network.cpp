class Solution {
public:
    
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& gp) {
        vector<vector<int>> adj(n);
        
        for(vector<int> &c:gp){
            int u = c[0];
            int v = c[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
vector<vector<int>> ans;
vector<bool> visited;
vector<int> tin, low;
int timer;

function<void(int,int)> dfs = [&](int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    for (int to : adj[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v])
                ans.push_back({v, to});
        }
    }
};

auto find_bridges = [&]() {
    timer = 0;
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs(i,-1);
    }
};
        
        
     find_bridges();   
        return ans;
    }
};