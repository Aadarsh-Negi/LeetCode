//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++
int dp[10055];
class Solution{   
public:
    bool solve(vector<int> &ar,int t,int i=0){
        if(t == 0) return 1;
        if(i>=ar.size()) return 0;
        if(dp[t] != -1) return dp[t];
        bool found = 0;
        for(int j=i;j<ar.size();j++)
            if(ar[j] <= t) found |= solve(ar,t-ar[j],j+1) ;
        // found |= solve(ar,t,i+1);
        return dp[t] = found;
    }
    bool isSubsetSum(vector<int>ar, int sum){
        
        int dp[104][10004] = {0};
        // memset(dp,-1,sizeof(dp));
        int n = ar.size();
        for(int i=0;i<n;i++) dp[i][0] = 1;
        
        if(ar[0] <= sum) dp[0][ar[0]] = 1;
        
        for(int i=1;i<n;i++){
            for(int j=1;j<=sum;j++){
                bool taken = false;
                if(ar[i] <= j){
                    taken = dp[i-1][j-ar[i]];
                }
                dp[i][j] = taken | dp[i-1][j];
            }
        }
        
        
        return dp[ar.size()-1][sum];
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends