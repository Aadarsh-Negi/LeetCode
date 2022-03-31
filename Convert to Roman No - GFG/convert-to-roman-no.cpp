// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    string convertToRoman(int n) {
          
        vector<int> val = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
        vector<string> ch = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
        
        
        string ans;
        while(n>0){
            
            for(int i=val.size()-1;i>=0;i--){
                if(val[i]<=n){
                    ans+=ch[i];
                    n-=val[i];
                    break;
                }   
            
            }
        }
        return ans;
        
    }
};

// { Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int N;
		cin>>N;
		Solution ob;
    	cout << ob.convertToRoman(N) << endl;
	}
	return 0;
}  // } Driver Code Ends