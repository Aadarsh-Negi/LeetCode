// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++
const int mod = 1000000007;
class Solution {
  public:
  map<pair<pair<int,int>,pair<int,int>>,int> dp;
  
   int solve(int s1,int s2,int e1,int e2,vector<vector<char>> &m){
      if(e1<0 || e2<0 || s1>=m.size() || s2>=m[0].size() || s1>e1 || s2>e2)
        return 0;
      
    if(m[e1][e2]!=m[s1][s2]) return 0;
    if((abs(e1-s1) + abs(e2-s2)) <=1) return 1;
    
    if(dp.count({{s1,s2},{e1,e2}})) return dp[{{s1,s2},{e1,e2}}];     
      
      
      
   
      
      
      
      long long temp=0;
      temp+=solve(s1+1,s2,e1-1,e2,m)%mod;
      temp+=solve(s1+1,s2,e1,e2-1,m)%mod;
      temp+=solve(s1,s2+1,e1,e2-1,m)%mod;
      temp+=solve(s1,s2+1,e1-1,e2,m)%mod;
      
    
      
      
      return dp[{{s1,s2},{e1,e2}}] = temp%mod;
        
  }
  
  
    int countPalindromicPaths(vector<vector<char>>m){
        return solve(0,0,m.size()-1,m[0].size()-1,m);
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>matrix(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> matrix[i][j];
		}
		Solution obj;
		int ans = obj.countPalindromicPaths(matrix);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends