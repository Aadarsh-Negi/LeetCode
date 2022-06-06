#define ll long long
class Solution {
public:
    
    int countHighestScoreNodes(vector<int>& par) {
        int ttl=par.size();
        
        vector<int> gg[par.size()];
        
        for(int i=1;i<par.size();i++) gg[par[i]].push_back(i);
        ll mx=-1;
        int cnt=0;
        
        function<int(int)> dfs = [&](int x){
        int l=0;
        int r=0;
        if(gg[x].size()) l = dfs(gg[x][0]);
        if(gg[x].size()>1) r = dfs(gg[x][1]);
        
        int lx=max(1,l);
        int rx=max(1,r);
        int tx =max(1,ttl-1-l-r);
        ll res = 1ll*lx*rx*tx;
            if(res>mx){
                mx=res;
                cnt=1;
            }else if(res==mx) cnt++;

            return l+r+1;
        };
        dfs(0);
        return cnt;
    }
};