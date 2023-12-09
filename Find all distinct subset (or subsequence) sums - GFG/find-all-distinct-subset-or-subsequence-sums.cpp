//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

int dp[102][10033];
class Solution {
public:
    int can(vector<int> &ar,int s,int i=0){
        if(s == 0) return 1;
        if(i >= ar.size() || s < 0) return 0;
        if(dp[i][s] != -1) return dp[i][s];
        bool x = can(ar,s-ar[i],i+1);
        x |= can(ar,s,i+1);
        return dp[i][s] = x;
    }
	vector<int> DistinctSum(vector<int>nums){
	    memset(dp,-1,sizeof(dp));
	    vector<int> ans;
	    int s = 0; for(int i:nums) s+=i;
	    for(int i=0;i<=s;i++){
	        if(can(nums,i) == 1){
	            ans.push_back(i);
	        }
	    }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution obj;
		vector<int> ans = obj.DistinctSum(nums);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}

// } Driver Code Ends