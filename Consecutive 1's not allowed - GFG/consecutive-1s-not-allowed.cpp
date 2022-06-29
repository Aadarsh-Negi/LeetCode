// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

 // } Driver Code Ends
//User function template for C++
class Solution{
public:
	// #define ll long long
	ll countStrings(int n) {
	    ll const mod = 1e9 + 7;
	    ll i = 0;
	    ll j = 1;
	    while(n--){
	        ll nx = i + j;
	        nx%=mod;
	        i = j;
	        j = nx;
	    }
	    i+=j;
	    i%=mod;
	    return i;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.countStrings(n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends