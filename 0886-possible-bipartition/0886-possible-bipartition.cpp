class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> par(n+55,-1);
        auto find = [&](auto &&find,int x){
            if(par[x]==-1) return x;
            return par[x] = find(find,par[x]);
        };
        vector<vector<int>> adj(n+1);
        for(auto it:dislikes){
            int a = it[0];
            int b = it[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        
        
        for(int i=1;i<=n;i++){
            for(int j:adj[i]){
                if(find(find,i)==find(find,j)) return false;
                
                int f = find(find,adj[i][0]);
                int k = find(find,j);
                if(f!=k)
                    par[f] = k;
            }
        }
        
        return true;
        
    }
};