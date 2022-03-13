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
    int ans;
    map<pair<int,int>,int> cnt;
    vector<vector<int>> ar;
    bool ok(int i,int j,int n,int m){
        if(i>n || j>m) return 1;
        
        if(cnt[{i,j}]==0) return 0;
        
        cout<<i<<" "<<j<<"\n";
        
        return ok(i+1,j,n,m) && ok(i,j+1,n,m) && ok(i+1,j+1,n,m);
        
        
    }
    
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
        ans=0;
        ar=artifacts;
        for(auto &it:dig) cnt[{it[0],it[1]}]=1;
        
        for(int i=0;i<ar.size();i++){
            int x = ar[i][0];
            int y = ar[i][1];
            int a = ar[i][2];
            int b = ar[i][3];
            if(ok(x,y,a,b)) ans++;
            cout<<"\n";
        }
        
     return ans;
        
    }
};