class Solution {
public:
    void dfs(int fix,int ind,vector<vector<int>> &graph,vector<int> &vis,vector<vector<int>> &ans){
        vis[ind]=1;
        for(int i=0;i<graph[ind].size();i++){
            if(!vis[graph[ind][i]]){
                ans[graph[ind][i]].push_back(fix);
                dfs(fix,graph[ind][i],graph,vis,ans);
            }
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        map<int,vector<int>> m;
        vector<vector<int>> ans(n);
        vector<vector<int>> graph(n);
        for(int i=0;i<edges.size();i++)
            graph[edges[i][0]].push_back(edges[i][1]);            
        for(int i=0;i<n;i++){
            vector<int> vis(n,0);
            dfs(i,i,graph,vis,ans);
        }
        return ans;
    }
};