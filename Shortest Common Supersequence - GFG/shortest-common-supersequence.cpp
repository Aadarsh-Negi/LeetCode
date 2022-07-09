// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

int  dp[104][104];
class Solution
{
    public:
    int solve(string &a,string &b,int i=0,int j=0){
        if(i>=a.size() || j>=b.size()) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int temp = 0;
        if(a[i] == b[j]) temp =  1+solve(a,b,i+1,j+1);
        temp = max(temp,solve(a,b,i+1,j));
        temp = max(temp,solve(a,b,i,j+1));
        return dp[i][j]= temp;
    }
    //Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        memset(dp,-1,sizeof(dp));
        int l = solve(X,Y);
        return (n+m) - l;
        //code here
    }
};

// { Driver Code Starts.

int main()
{   
    
    int t;
    
    //taking total testcases
    cin >> t;
    while(t--){
    string X, Y;
    //taking String X and Y
	cin >> X >> Y;
	
	//calling function shortestCommonSupersequence()
	Solution obj;
	cout << obj.shortestCommonSupersequence(X, Y, X.size(), Y.size())<< endl;
    }
	return 0;
}

  // } Driver Code Ends