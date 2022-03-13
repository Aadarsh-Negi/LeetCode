	#define ll long long
	#define pb push_back
	#define ppb pop_back
	#define ins insert
	#define pll pair<ll,ll>
	#define ff first
	#define lb lower_bound
	#define ub upper_bound
	#define ss second
	#define mset multiset
	#define vi vector<int>
	#define vs vector<string>
	#define vvi vector<vi>
	#define umap unordered_map
	#define allr(xxx90) xxx90.begin(),xxx90.end(),greater<int>()
	#define all(xxx90) xxx90.begin(),xxx90.end()
	int getmx(vector<int> &ar){return *max_element(all(ar));}
	int getmn(vector<int> &ar){return *min_element(all(ar));}
	int mnind(vector<int> &ar){return min_element(all(ar))-ar.begin();}
	int mxind(vector<int> &ar){return max_element(all(ar))-ar.begin();}
	int gcd(int a,int b){ return __gcd(a,b);}
	int lcm(int a,int b){ return ((a/__gcd(a,b))*b);}
	ll add_mod(ll a,ll b,ll m){return ((((a%m)+(b%m))%m + m)%m);}
	ll subs_mod(ll a,ll b,ll m){return ((((a%m)-(b%m))%m + m)%m);}
	ll mult_mod(ll a,ll b,ll m){return ((((a%m)*(b%m))%m + m)%m);}
	ll power(ll x, ll y){ ll res = 1ll; while (y > 0ll) { if (y & 1ll)res = res * x; y = y >> 1ll; x = x * x;}return res;}
	ll power_mod(ll x, ll y,ll mod){ ll res = 1ll; while (y > 0ll) { if (y & 1ll) res = mult_mod(res, x,mod); y = y >> 1ll; x = mult_mod(x,x,mod);}return res;}
	const ll mod=1000000007;
	const ll inf = 1e18; 
	const ll mod2=998244353;
 
class Solution {
public:
 
     vector<vector<pair<ll, ll> > > adj;
    vector<vector<pair<ll, ll> > > adj2;
  void dijk(int s,int n,vector<long long> &dis){
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> pq;
        
        vector<long long> vis(n+1,0);
        dis[s]=0;
        pq.push({0,s});
        while(!pq.empty()){
            long long prev=pq.top().second;
            long long d=pq.top().first;
            vis[prev]=1;
            pq.pop();
            if(dis[prev]!=d)continue;
            for(auto it:adj[prev]){
                long long nxt=it.first;
                long cost=it.second;
                if(!vis[nxt] && dis[nxt]>dis[prev]+cost){
                    dis[nxt]=dis[prev]+cost;
                    pq.push({dis[nxt],nxt});
                }
            }
        }
        // return dis;
    }
    void dijk2(int s,int n,vector<long long> &dis){
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> pq;
        
        vector<long long> vis(n+1,0);
        dis[s]=0;
        pq.push({0,s});
        while(!pq.empty()){
            long long prev=pq.top().second;
            long long d=pq.top().first;
            vis[prev]=1;
            pq.pop();
            if(dis[prev]!=d)continue;
            for(auto it:adj2[prev]){
                long long nxt=it.first;
                long cost=it.second;
                if(!vis[nxt] && dis[nxt]>dis[prev]+cost){
                    dis[nxt]=dis[prev]+cost;
                    pq.push({dis[nxt],nxt});
                }
            }
        }
        // return dis;
    }
    
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        adj.clear();
	    adj.resize(n + 1);
        adj2.clear();
	    adj2.resize(n + 1);
       
        for(auto &it:edges) adj[it[0]].pb({it[1],it[2]}),adj2[it[1]].pb({it[0],it[2]});;
         
            
        ll ans=inf;
        vector<long long> a(n + 1, inf);
        vector<long long> b(n + 1, inf);
        vector<long long> dd(n + 1, inf);
        dijk(src1,n,a);
        dijk(src2,n,b);
        dijk2(dest,n,dd);
        
        for(int i=0;i<n;i++){
            ans=min(ans,a[i]+b[i]+dd[i]);
        }
        if(ans==inf) ans=-1;
        return ans;
        
        
        
      
    
    }
};