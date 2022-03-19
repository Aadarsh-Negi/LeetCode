// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
      vector<int> dp;
      int n;
    bool solve(int i,int nums[]){
        if(i>=n-1) return 1;
        
        if(dp[i]!=-1) return dp[i];
        
        for(int j=nums[i];j>=1;j--){
           dp[i] = solve(i+j,nums);
            if(dp[i]==1) return dp[i];
        }
        return 0;
        
    }
    int canReach(int A[], int N) {
       dp.resize(N+1);
       n=N;
        fill(dp.begin(),dp.end(),-1);
        return solve(0,A);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.canReach(A,N) << endl;
    }
    return 0;
}  // } Driver Code Ends