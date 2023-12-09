//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int subsetPairNotDivisibleByK(int arr[], int N, int K) ;

//  Driver code to test above methods
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int a[n+5];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        cout << subsetPairNotDivisibleByK(a, n, k) << "\n";
    }
    return 0;
}
// } Driver Code Ends


int subsetPairNotDivisibleByK(int ar[], int n, int k) 
{
    
    
    
    int cnt[k+1] = {0};
    
    for(int i=0;i<n;i++){
      ar[i]%=k;  
      cnt[ar[i]]++;
    //   cout<<ar[i]<<" ";
    } 
    // cout<<"\n";
    
    int ans = (cnt[0] >= 1);
    if(k%2 == 0) cnt[k/2] = min(cnt[k/2],1);
    
    for(int i=1;i<=k/2;i++){
            ans += max(cnt[i],cnt[k-i]);
    }
    
    return ans;
    
 // 0 1 2 0    
}