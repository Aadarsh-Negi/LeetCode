//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
int const N = 2e5 + 55;
int dp[N];

class Solution{
    public:
    bool solve(vector<int> &a,int k,int m,int i=0){
        if(i >= a.size()) return 1;
        if(dp[i] != -1) return dp[i];
        bool can = 0;
        for(int j=i+k-1;j<a.size();j++){
            if(a[j] - a[i] > m) return false;
            if(solve(a,k,m,j+1)) return dp[i] = true;
        }
        return dp[i] = false;
    }
    bool partitionArray(int N, int K, int M, vector<int> &A){
        sort(A.begin(),A.end());
        memset(dp,-1,sizeof(dp));
        return solve(A,K,M);
    }
};

//{ Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N, K, M;
        cin >> N >> K >> M;
        vector<int> A(N);
        for(int i = 0; i < N; i++){
            cin >> A[i];
        }
        Solution obj;
        bool ans = obj.partitionArray(N, K, M, A);
        if(ans){
            cout << "YES\n";
        }
        else{
            cout<< "NO\n";
        }
    }
}

// } Driver Code Ends