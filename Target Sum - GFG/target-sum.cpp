// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
      int solve(int i,int tar,vector<int> &ar,map<pair<int,int>,int> &dp){
       
        
        if(i>=ar.size()){
            return !tar;
        }
        
        if(dp.count({i,tar})) return dp[{i,tar}];
        
        
        return dp[{i,tar}] = solve(i+1,tar-ar[i],ar,dp) + solve(i+1,tar+ar[i],ar,dp);
        
        
        
        
    }
    int findTargetSumWays(vector<int>& nums, int tar) {
        // int n = nums.size();
        map<pair<int,int>,int> dp;
        
        
        return solve(0,tar,nums,dp);
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>arr(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>arr[i];
        }
        int target;
        cin >> target;

        Solution ob;
        cout<<ob.findTargetSumWays(arr,target);
        cout<<"\n";
    }
    return 0;
}  // } Driver Code Ends