#define ll long long
#define pb push_back
#define ppb pop_back
#define ins insert
#define ff first
#define lb lower_bound
#define ub upper_bound
#define ss second
#define mset multiset
#define vi vector<int>
#define vs vector<string>
#define vvi vector<vi>
#define umap unordered_map
#define all(xxx90) xxx90.begin(),xxx90.end()
#define allr(xxx90) xxx90.rbegin(),xxx90.rend()
template<class T> using mxpq = priority_queue<T>;
template<class T> using mnpq = priority_queue<T, vector<T>, greater<T>>;
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
    vector<int> arrayChange(vector<int>& ar, vector<vector<int>>& op) {
        
//         vector<int> par(3000005,-1);
//         // vec
//         function<int(int x)> find = [&](int x){
//             if(par[x]==-1) return x;
//             return par[x] = find(par[x]);
//         };
        
        // sort(all(op));
        
        // map<ll,vector<ll>> mp;
        umap<ll,ll> mp;
        // map<pair<ll,ll>,ll> tm;
        // ll cur=0;
        
        for(ll i=0;i<ar.size();i++) mp[ar[i]] = i;
        
        for(ll i=0;i<op.size();i++){
            ll x = op[i][0];
            ll y = op[i][1];
            // if(x==y) continue;
            // par[y] = x;
            mp[y] = mp[x];
            ar[mp[x]] = y;
            // tm[{x,y}]=cur++;
            // adj[x].pb(y);
        }

        
        return ar;
        
    }
};