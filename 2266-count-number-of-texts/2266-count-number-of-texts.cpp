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
    ll ans;
    string ss;
    
    vector<int> dp;
    set<string> code;
    ll solve(int i){
        if(i>=ss.size()) return 1;
        if(dp[i]!=-1) return dp[i];
        ll temp=0;
        string cur;
        for(int j=i;j<ss.size();j++){
            cur+=ss[j];
            if(code.count(cur)){
                temp+=solve(j+1);
                temp%=mod;
            }else break;
        }
        return dp[i] = temp;
        
        
    }
    
    int countTexts(string s) {
        ans=0;
        ss=s;
        dp.resize(s.size()+4,-1);
        code.ins("2");
        code.ins("22");
        code.ins("222");
        code.ins("3");
        code.ins("33");
        code.ins("333");
        code.ins("4");
        code.ins("44");
        code.ins("444");
        code.ins("5");
        code.ins("55");
        code.ins("555");
        code.ins("6");
        code.ins("66");
        code.ins("666");
        code.ins("7");
        code.ins("77");
        code.ins("777");
        code.ins("7777");
        code.ins("8");
        code.ins("88");
        code.ins("888");
        code.ins("9");
        code.ins("99"); 
        code.ins("999"); 
        code.ins("9999");
        return solve(0);
    }
};