class Solution {
public:
    int ans;
    vector<int> vis;
    int n;
    void solve(int cnt=1){
        
        if(cnt==n+1){
            ans++;
            return;
        }
        
        for(int i=1;i<=n;i++){
            if(vis[i] || ((i%cnt!=0) && (cnt%i!=0))) continue;
            vis[i]=1;
            solve(cnt+1);
            vis[i]=0;
        }
    }
    
    int countArrangement(int n) {
        vis.resize(n+1,0);
        this->n = n;
        solve();
        return ans;
    }
};