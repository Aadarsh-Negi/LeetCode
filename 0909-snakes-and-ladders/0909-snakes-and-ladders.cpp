class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& b) {
        int n = b.size();
        for(int i=0;i<n/2;i++)
            for(int j=0;j<n;j++)
                swap(b[i][j],b[n-1-i][j]);
    
        for(int i=1;i<n;i+=2){
            for(int j=0;j<n/2;j++)
                swap(b[i][j],b[i][n-1-j]);
        }
            
        queue<int> qq;
        
        qq.push(0);
        int ans=0;
        
        while(qq.size()){
            int sz = qq.size();
            while(sz--){
                int cur2 = qq.front();
                qq.pop();
                
                // cout<<cur<<"\n";
                if(cur2 == n*n - 1) return ans;
                
                for(int d=1;d<=6 && cur2+d<n*n;d++){
                    int cur = cur2 + d;
                    int x = cur/n;
                    int y = cur%n;
                    if(b[x][y]==-1000) continue;
                    if(b[x][y] > 0) qq.push(b[x][y] - 1);
                    else qq.push(cur);
                    b[x][y] = -1000;
                }

            }
            ans++;
        }
        
    
        return -1;
    }
};