// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution {
public:
int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    vector<int> dis(n,1000);
	    dis[0]=0;
	    
	    
	    for(int i=0;i<n-1;i++){
	        for(auto it: edges)
	            dis[it[1]]= min(dis[it[1]],dis[it[0]]+it[2]);
	    }
	    vector<int> dis2 = dis;
	    for(auto it: edges){
	         dis[it[1]]= min(dis[it[1]],dis[it[0]]+it[2]);
	    }
	    return dis!=dis2;

	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends