int const N = 55;
vector<int> adj[N];
int lvl[N];
int par[N];
int times[N];
pair<int,int> dp[N];
class Solution {
public:
void dfs(int node, int l,int p){
   lvl[node] = l;
   par[node] = p;
   
   for(int child : adj[node])
   {
      if(child != p)
        dfs(child, l+1, node);
   }
}
 
int LCA(int a, int b){ 
   
   if(lvl[a] > lvl[b])
    swap(a, b);
   int diff = lvl[b] - lvl[a];
    
   while(diff != 0)
   {
      b = par[b];
      diff--;
   }
    
   if(a == b)
    return a;
    
   while(a != b)
    a=par[a], b=par[b];
 
   return a;
}
 
vector<int> path(int a, int b, int n){
    int lca = LCA(a, b);
    vector<int> path;
    while(a != lca)
      path.push_back(a), a = par[a];
 
    path.push_back(a);
 
    vector<int> temp;
    while(b != lca)
      temp.push_back(b), b=par[b];
    reverse(temp.begin(), temp.end());
    for(int x : temp)
      path.push_back(x);
   
   return path;
}
    
    pair<int,int> solve(vector<int> &price,int cur = 0,int p=-1){
        if(dp[cur].first!=-1) return dp[cur];
        
           int temp = (price[cur]/2)*times[cur];
           int t2 = (price[cur])*times[cur];
            
           for(int i:adj[cur]){
               if(i!=p){
                   auto x = solve(price,i,cur);
                   temp+=x.second;
                   t2+=min(x.first,x.second);
               }
           }
            return dp[cur] = {temp,t2};

    }
    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
        for(int i=0;i<=n;i++){
            adj[i].clear();
            times[i] = 0;
            dp[i].first = dp[i].second = -1;
        }
        
        for(auto it:edges){
            int a = it[0];
            int b = it[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        dfs(1, 0, -1);
        
        for(auto it:trips){
            int a = it[0];
            int b = it[1];
            for(int i:path(a,b,n))
                times[i]++;
        }
        
        // for(int i=0;i<n;i++) cout<<times[i]<<" ";cout<<"\n";
        auto it = solve(price);
        int ans = min({it.first,it.second});
        return ans;
        // return min(solve(price),solve(price));
                
        
    }
};