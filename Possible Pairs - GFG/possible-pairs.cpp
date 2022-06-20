// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int pairCount(int x, int y){
        if(y%x) return 0;
        int axb = y/x;
        
        int ans=0;
        for(int i=2;i*i<=axb;i++){
            if(axb%i==0){
                ans++;
                while(axb%i==0){
                    axb/=i;
                }
            }
        }
        if(axb>1) ans++;
        
        return (1<<ans);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int x, y;
        cin>>x>>y;
        
        Solution ob;
        cout<<ob.pairCount(x, y)<<endl;
    }
    return 0;
}  // } Driver Code Ends