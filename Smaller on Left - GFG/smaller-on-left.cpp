// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


vector<int> Smallestonleft(int arr[], int n);


int main() {
	
	int t;
	
	cin >> t;
	
	while(t--){
	    
	    int n;
	    cin >> n;
	    int arr[n+1];
	    
	    for(int i=0;i<n;i++){
	        cin>> arr[i];
	    }
	    
	    vector<int> b;
	    b = Smallestonleft(arr, n);
	    for(int i=0;i<n;i++)
	        cout << b[i] << " ";
	       
	    cout << endl;
	    
	    
	}
	
	return 0;
}// } Driver Code Ends


vector<int> Smallestonleft(int arr[], int n)
{
    
    vector<int> ans(n);
    
    set<int> ar;
    
    
    for(int i=0;i<n;i++){
        
        int val = arr[i];
        ar.insert(val);
        
        auto it = ar.lower_bound(val);
        if(it==ar.begin())  ans[i]=-1;
        else ans[i]= *(--it);
        
    }
   
    return ans;
    // Complete the function
}