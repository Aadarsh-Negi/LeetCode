int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
class Solution {
public:
    int minCost(vector<vector<int>>& g) {
        int n = g.size();
        int m = g[0].size();
        queue<pair<int,int>> qq;
        qq.push({0,0});
        vector<vector<int>> dis(n,vector<int>(m,INT_MAX));
        
        dis[0][0] = 0;
        
        while(qq.size()){
            int sz = qq.size();
            while(sz--){
                int i = qq.front().first;
                int j = qq.front().second;
                qq.pop();
                
                int c = g[i][j]-1;
                
                for(int k=0;k<4;k++){
                    int x = i+dx[k];
                    int y = j+dy[k];
                    if(x < 0 || y<0 || x>=n || y>=m) continue;
                    
                    int p = dis[x][y];
                    dis[x][y] = min(dis[x][y],dis[i][j] + (c!=k));
                    if(p!=dis[x][y]) qq.push({x,y});
                }
                
            }
        }
        return dis[n-1][m-1];
        
    }
};