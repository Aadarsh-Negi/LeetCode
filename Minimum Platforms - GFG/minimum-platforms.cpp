// { Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int ar[], int dep[], int n){
        priority_queue<int> qq;
        vector<pair<int,int>> ax;
        for(int i=0;i<n;i++){
            ax.push_back({ar[i],dep[i]});
        }
        sort(ax.begin(),ax.end());
        // ,[&](pair<int,int> &a,pair<int,int> &b){
        //     return a.second<b.second;
        // });
        
        int use=0;
        int mx=0;
        
        for(int i=0;i<n;i++){
            while(qq.size() && (-qq.top())<ax[i].first){
                use--;
                qq.pop();
            }
            if(use<mx){
                use++;
            }else use++,mx++;
            
            qq.push({-ax[i].second});
        }
        return mx;
        
        
        
       
    }
};


// { Driver Code Starts.
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
}  // } Driver Code Ends