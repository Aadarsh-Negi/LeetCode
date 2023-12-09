//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method */

int r;
class Solution{
  public:
    
    bool solve(int a[],int n,int k,int s,int mask=0){
        if(s == 0 && k == 1 && mask == ((1<<n) - 1)){
            return true;
        }
        
        if(k == 0 || s < 0 || mask == ((1<<n)-1)) return false;
        bool can = 0;
        
        if(s == 0){
            return solve(a,n,k-1,r,mask);
        }
        
        
        for(int i=0;i<n;i++){
            if(mask&(1<<i));
            else{
                can |= solve(a,n,k,s-a[i],mask|(1<<i));
            }
        }
        return can;
    }
    
  
    bool isKPartitionPossible(int a[], int n, int k)
    {
         int s = 0;
         for(int i=0;i<n;i++) s+=a[i];
         if(s%k != 0) return false;
         s/=k;
         r = s;
         return solve(a,n,k,s);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	
    	cin>>n;
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	int k;
    	cin>>k;
    	Solution obj;
    	cout<<obj.isKPartitionPossible(a, n, k)<<endl;
    }
}
// } Driver Code Ends