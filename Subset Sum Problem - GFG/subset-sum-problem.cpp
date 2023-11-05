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
        found |= solve(ar,t,i+1);
        return dp[t] = found;
    }
    bool isSubsetSum(vector<int>arr, int sum){
        memset(dp,-1,sizeof(dp));
        return solve(arr,sum);
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