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
const ll mod = 1000000007;
const ll inf = 1e18; 
const ll mod2 = 998244353;

class Solution {
public:
    int n,m;
    vvi cnt;
    vvi g;
    int const mod = 1e9 + 7;
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,-1,1};
    int dfs(int i,int j){
        
        if(cnt[i][j]!=-1) return cnt[i][j];
        int t=0;
        for(int k=0;k<4;k++){
            int ix = i + dx[k];
            int jx = j + dy[k];
            if(ix<0 || jx<0 || ix>=n || jx>=m) continue;
            
            if(g[i][j] < g[ix][jx])
                t+=1+dfs(ix,jx);
            t%=mod;
        }
        return cnt[i][j] = t;
    }
    int countPaths(vector<vector<int>>& g2) {
        g=g2;
        n = g.size();
        m = g[0].size();
        cnt.resize(n,vi(m,-1));
        
        long long ans=n*m;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++){
                 for(int k=0;k<4;k++){
                    int ix = i + dx[k];
                    int jx = j + dy[k];
                    if(ix<0 || jx<0 || ix>=n || jx>=m) continue;
                    if(g[ix][jx] > g[i][j])
                        ans+=1+dfs(ix,jx),ans%=mod;
                    
                }
            }
                  
        }
        return ans;
    }
};