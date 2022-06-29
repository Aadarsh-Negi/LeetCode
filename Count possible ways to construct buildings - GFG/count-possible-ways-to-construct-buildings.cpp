// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int TotalWays(int N)
	{
	    long long  i = 0;
	    long long j = 1;
	    long long const mod = 1e9 + 7;
	    
	    while(N--){
	        long long nx = i+j;
	        nx%=mod;
	        i=j;
	        j=nx;
	    }
	    
	    i+=j;
	    i%=mod;
	    
	    i = i*i;
	    i%=mod;
	    
	    return i;
	    // Code here
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends