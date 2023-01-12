class Solution {
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string lab) {
    vector<int> ans(n);
    vector<vector<int>> adj(n);
        for(auto xx:edges){
            int a = xx[0];
            int b = xx[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        
        auto dfs = [&](auto &&dfs,int i,int p)->vector<int>{
            vector<int> cnt(27);
            for(int x:adj[i]){
                if(x!=p){
                    vector<int> t = dfs(dfs,x,i);
                    for(int i=0;i<27;i++) cnt[i]+=t[i];
                }
            }
            cnt[lab[i]-'a']++;
            ans[i] = cnt[lab[i]-'a'];
            return cnt;
        };
        
        dfs(dfs,0,-1);
        
        return ans;
    }
};