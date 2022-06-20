// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++
#define ll long long
ll power(ll x, ll y){ ll res = 1ll; while (y > 0ll) { if (y & 1ll)res = res * x; y = y >> 1ll; x = x * x;}return res;}
class Solution{
public:
    long long getSmallestDivNum(long long n){
        
        map<int,int> pr;
        for(long long val= 1;val<=n;val++){
            long long i =val;
            for(long long j=2;j*j<=i;j++){
                if(i%j==0){
                    int cnt=0;
                    while(i%j==0){
                        cnt++;
                        i/=j;
                    }
                    pr[j] = max(pr[j],cnt);
                }
            }
            if(i>1) pr[i] = max(pr[i],1);
            
        }
        long long ans = 1;
        for(auto it:pr){
            ans*=power(it.first,it.second);
        }
        return ans;
        
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Solution ob;
        cout<< ob.getSmallestDivNum(n)<<endl;
    }
    return 0;
}  // } Driver Code Ends