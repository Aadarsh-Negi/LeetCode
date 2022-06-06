#define ll long long
class Solution {
public:
    int countHighestScoreNodes(vector<int>& par) {
        vector<vector<int>> adj(par.size());
        
        for(int i=1;i<par.size();i++)
            adj[par[i]].push_back(i);
        
        vector<pair<int,int>> sub(par.size());
        
        
        function<int(int)> dfs = [&](int x){
            int l = 0;
            int r = 0;
            if(adj[x].size()) l = dfs(adj[x][0]);
            if(adj[x].size()>1) r = dfs(adj[x][1]);
            sub[x] = {l,r};
            return l+r+1;
        };
        dfs(0);
        
        ll ans=0;
        int ttl = par.size();
        
        for(auto &[l,r]:sub)
            // cout<<l<<" "<<r<<"\n";
         ans = max(ans,1ll*max(1,l)*max(1,r)*max(1,(ttl-1-l-r)));
        int cnt=0;
        
        for(auto &[l,r]:sub)
           if(ans==1ll*max(1,l)*max(1,r)*max(1,(ttl-1-l-r))) cnt++;
        
        return cnt;

    }
};