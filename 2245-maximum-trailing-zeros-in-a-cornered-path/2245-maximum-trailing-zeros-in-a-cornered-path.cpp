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
    int n,m;
    int maxTrailingZeros(vector<vector<int>>& gg2) {
       n=gg2.size();
       m=gg2[0].size();
        int ans=0;
        vvi hr(n+3,vi(m+3,0));
        vvi vt(n+3,vi(m+3,0));
            vvi gg(n,vi(m,0));
        vvi hr2(n+3,vi(m+3,0));
        vvi vt2(n+3,vi(m+3,0));
        
      for(int i=0;i<n;i++){
          for(int j=0;j<m;j++){
              int cnt=0;
              int val=gg2[i][j];
              while(val && val%5==0) cnt++,val/=5;
              gg2[i][j]=cnt;
              cnt=0;
              while(val && val%2==0) cnt++,val/=2;
              gg[i][j]=cnt;
              
              
          }
      }
        
      for(int i=1;i<=n;i++){
          for(int j=1;j<=m;j++){
              hr[i][j] = hr[i][j-1] + gg2[i-1][j-1];
              vt[i][j] = vt[i-1][j] + gg2[i-1][j-1];
          }
      }

        for(int i=1;i<=n;i++){
          for(int j=1;j<=m;j++){
              hr2[i][j] = hr2[i][j-1] + gg[i-1][j-1];
              vt2[i][j] = vt2[i-1][j] + gg[i-1][j-1];
          }
      }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                
                int left = hr[i][j];
                int right = hr[i][m]-hr[i][j-1];
                int up = vt[i][j];
                int down = vt[n][j] - vt[i-1][j];
                
                int left2 = hr2[i][j];
                int right2 = hr2[i][m]-hr2[i][j-1];
                int up2 = vt2[i][j];
                int down2 = vt2[n][j] - vt2[i-1][j];
                
                int v2 = gg[i-1][j-1];
                int v5 = gg2[i-1][j-1];
                
                int ans1 = min(left + up - v5,left2 + up2 - v2);
                int ans2 = min(left + down - v5,left2 + down2 - v2);
                int ans3 = min(right + up - v5,right2 + up2 - v2);
                int ans4 = min(right + down - v5,right2 + down2 - v2);
                ans=max({ans,ans1,ans2,ans3,ans4});
                
            }
        }
   
           
           return ans;
      
           
    }
};