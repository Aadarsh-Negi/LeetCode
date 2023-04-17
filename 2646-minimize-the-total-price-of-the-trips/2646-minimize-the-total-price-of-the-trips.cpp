const int MAX_N = 55;
const int LOG = 14;
vector<int> adj[MAX_N];
int up[MAX_N][LOG]; // up[v][j] is 2^j-th ancestor of v
int depth[MAX_N];
int par[MAX_N];
int times[MAX_N];

class Solution {
public:


void dfs(int a,int p) {
    par[a]=p;
	for(int b : adj[a]) {
        if(b!=p){
            depth[b] = depth[a] + 1;
            up[b][0] = a; // a is parent of b
            for(int j = 1; j < LOG; j++) {
                up[b][j] = up[up[b][j-1]][j-1];
            }
            dfs(b,a);    
        }
	}
}

int get_lca(int a, int b) { // O(log(N))
	if(depth[a] < depth[b]) {
		swap(a, b);
	}
	// 1) Get same depth.
	int k = depth[a] - depth[b];
	for(int j = LOG - 1; j >= 0; j--) {
		if(k & (1 << j)) {
			a = up[a][j]; // parent of a
		}
	}
	// 2) if b was ancestor of a then now a==b
	if(a == b) {
		return a;
	}
	// 3) move both a and b with powers of two
	for(int j = LOG - 1; j >= 0; j--) {
		if(up[a][j] != up[b][j]) {
			a = up[a][j];
			b = up[b][j];
		}
	}
	return up[a][0];
}
 
vector<int> path(int a, int b){
    int lca = get_lca(a, b);
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
        
           int temp = (price[cur]/2)*times[cur];
           int t2 = (price[cur])*times[cur];
            
           for(int i:adj[cur]){
               if(i!=p){
                   auto x = solve(price,i,cur);
                   temp+=x.second;
                   t2+=min(x.first,x.second);
               }
           }
            return {temp,t2};

    }
    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
        for(int i=0;i<=n;i++){
            adj[i].clear();
            times[i] = 0;
        }
        
        for(auto it:edges){
            int a = it[0];
            int b = it[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        dfs(0, 0);
        
        for(auto it:trips){
            int a = it[0];
            int b = it[1];
            for(int i:path(a,b))
                times[i]++;
        }
        
        auto it = solve(price);
        int ans = min({it.first,it.second});
        return ans;
                
        
    }
};