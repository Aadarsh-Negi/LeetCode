// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
	public:
	map<pair<int,int>,set<string>> done;
	set<string> solve(int i,int j,string &s,string &t,vector<vector<int>>&dp){
	    
	        if(done[{i,j}].size()) return done[{i,j}];
	        set<string> cur;
	        
	        if(i<=0 || j<=0){
	            cur.insert("");
	            return cur;
	        }
	        
	        if(s[i-1]==t[j-1]){
	            cur = solve(i-1,j-1,s,t,dp);
	            set<string> temp;
	            for(string st:cur){
	                string ss =  st +s[i-1];
	                temp.insert(ss);
	            }
	            cur=temp;
	        }else{
	            
	            set<string> temp;
	            
	            if(dp[i-1][j] >= dp[i][j-1]){
	                cur = solve(i-1,j,s,t,dp);        
	            }
	            
	            if(dp[i-1][j] <= dp[i][j-1]){
	                temp = solve(i,j-1,s,t,dp);
	            }
	            for(string st:temp){
	                cur.insert(st);
	            }
	            
	        }
	        
	        done[{i,j}] = cur;
	        return cur;
	        
	    }
	    
	
	
		vector<string> all_longest_common_subsequences(string s, string t)
		{
		    
		    int n=s.length();
		    int m=t.length();
		 vector<vector<int>>dp(n+5,vector<int>(m+5,-1));
		   
		   
		   for(int i=0;i<=n;i++)
		   {
		       for(int j=0;j<=m;j++)
		       {
		           if(i==0 || j==0)
		            dp[i][j]=0;
		            
		            else if(s[i-1]==t[j-1])
		            {
		                dp[i][j]=1+dp[i-1][j-1];
		            }
		            else
		            {
		                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		            }
		       }
		   }
		   
		   
		   vector<string>ans;
		   
		   
		  set<string> mp = solve(n,m,s,t,dp);
		  for(string s:mp) ans.push_back(s);
		  
		  
		  return ans;
		}
};



// { Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	string s, t;
    	cin >> s >> t;
    	Solution ob;
    	vector<string> ans = ob.all_longest_common_subsequences(s, t);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}

  // } Driver Code Ends