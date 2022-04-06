// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    long long ans = 0;
    
    void merge(long long arr[],long long l,long long mid,long long r){
        
        long long temp[r-l+2];
        long long k=0;
        
        long long i,j;
        i=l;
        j=mid+1;
        
        while(i<=mid && j<=r){
            if(arr[i]>arr[j]){
                ans+=mid-i+1;
                temp[k++]=arr[j++];
            }else temp[k++]=arr[i++];
        }
        
        while(i<=mid)temp[k++]=arr[i++];
        while(j<=r)temp[k++]=arr[j++];
        
        k=0;
        while(l<=r){
            arr[l++]=temp[k++];
        }
        
        
    }
    
    void count(long long arr[],long long l,long long r){
        if(l>=r)return;
        
        long long mid = l + (r-l)/2;
        
        count(arr,l,mid);
        count(arr,mid+1,r);
        
        merge(arr,l,mid,r);
        
        
    }
    long long int inversionCount(long long arr[], long long N){
        
        count(arr,0,N-1);
        
        return ans;
        
        
    }

};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends