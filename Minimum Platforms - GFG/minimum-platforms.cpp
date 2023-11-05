//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int ar[], int dep[], int n)
    {
        map<int,int> rr;
        
        for(int i=0;i<n;i++){
            rr[ar[i]]++;
            rr[dep[i]+1]--;
        }
        
        int mx = 0;
        int cur = 0;
        for(auto it:rr){
            cur+=it.second;
            mx = max(mx,cur);
        }
        
        
        return mx;
        
    	// Your code here
    }
};


//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}
// } Driver Code Ends