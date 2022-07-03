class Solution {
public:
    vector<vector<int>> ans;
    int n;
    void dfs(int u,vector<vector<int>>& g,vector<int> temp = {}){
        temp.push_back(u);
        if(u==n-1){
            ans.push_back(temp);
            return;
        }
        for(int v:g[u])
            dfs(v,g,temp);   
        temp.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        n=graph.size();
        dfs(0,graph);
        return ans;
    }
};