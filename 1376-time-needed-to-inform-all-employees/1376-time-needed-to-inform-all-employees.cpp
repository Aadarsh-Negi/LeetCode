int const N = 1e5 + 2;
vector<int> adj[N];
class Solution {
public:
    
    void solve(vector<int> &tt,int cur,int &ans,int temp=0){
        if(adj[cur].size() == 0){
            ans = max(ans,temp);
            return;
        }
        
        for(int i:adj[cur]){
            solve(tt,i,ans,temp + tt[cur]);
        }
    }
    
    int numOfMinutes(int n, int root, vector<int>& par, vector<int>& tt) {
        for(int i=0;i<n;i++) adj[i].clear();
        
        for(int i=0;i<n;i++){
            if(i!=root)
                adj[par[i]].push_back(i);
        }
        
        int mx = 0;
        
        solve(tt,root,mx);
        return mx;
        
        
    }
};