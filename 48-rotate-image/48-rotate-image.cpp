class Solution {
public:
    void rotate(vector<vector<int>>& ar) {
       int n=ar.size();
for(int i=0;i<n;i++)
	for(int j=i+1;j<n;j++) swap(ar[i][j],ar[j][i]);

for(int i=0;i<n;i++)
	for(int j=0;j<n/2;j++) swap(ar[i][j],ar[i][n-j-1]);

        
        
    }
};