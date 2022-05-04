class Solution {
public:
    vector<vector<int>> adj;
    bool canFinish(int n, vector<vector<int>>& pre) {
        adj.resize(n);
        vector<int> vis(n,0);
        for(auto it:pre){
            adj[it[1]].push_back(it[0]);
            vis[it[0]]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++) if(vis[i]==0) q.push(i);
        
        
         while (!q.empty()) {
        int curr = q.front(); q.pop(); n--;
        for (auto next: adj[curr])
            if (--vis[next] == 0) q.push(next);
    }
    return n == 0;
        
        
        
    }
};