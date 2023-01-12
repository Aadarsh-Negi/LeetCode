
class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& app) {
        vector<vector<int>> adj(n);
        for(auto xx:edges){
            int a = xx[0];
            int b = xx[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        
        auto dfs = [&](auto &&dfs,int i,int p)->int{
            int c=0;
            for(int x:adj[i]){
                if(x!=p){
                    c+=dfs(dfs,x,i);
                }
            }
            return ((app[i] || c) ? c+2:c);
        };
        
        return max(0,dfs(dfs,0,-1)-2);
    }
};

// 0 1 4 1 5 1 0 2 3 2 6 