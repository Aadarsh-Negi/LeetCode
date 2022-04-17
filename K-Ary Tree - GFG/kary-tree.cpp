// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
#define ll long long
const ll mod=1000000007;
ll add_mod(ll a,ll b,ll m){return ((((a%m)+(b%m))%m + m)%m);}
ll subs_mod(ll a,ll b,ll m){return ((((a%m)-(b%m))%m + m)%m);}
ll mult_mod(ll a,ll b,ll m){return ((((a%m)*(b%m))%m + m)%m);}
ll power_mod(ll x, ll y,ll mod){ ll res = 1ll; while (y > 0ll) { if (y & 1ll) res = mult_mod(res, x,mod); y = y >> 1ll; x = mult_mod(x,x,mod);}return res;}
class Solution {
  public:
    long long karyTree(int k, int m) {
        return power_mod(k,m,mod);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int k,m;
        
        cin>>k>>m;

        Solution ob;
        cout << ob.karyTree(k,m) << endl;
    }
    return 0;
}  // } Driver Code Ends