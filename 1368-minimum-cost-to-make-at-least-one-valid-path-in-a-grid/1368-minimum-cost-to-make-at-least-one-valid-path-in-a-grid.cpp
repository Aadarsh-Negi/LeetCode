int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
class Solution {
public:
    int minCost(vector<vector<int>>& g) {
        const int n = g.size();
        const int m = g[0].size();
        deque<pair<int,int>> qq;
        qq.push_back({0,0});
        vector<vector<int>> distance(n,vector<int>(m,INT_MAX/2));
        distance[0][0] = 0;
        while(qq.size()){
                int i = qq.front().first;
                int j = qq.front().second;
                qq.pop_front();
                if(i==n-1 && j==m-1) return distance[i][j];
                int c = g[i][j]-1;
                for(int k=0;k<4;k++){
                    int x = i+dx[k];
                    int y = j+dy[k];
                    if(x<0 || y<0 || x>=n || y>=m) continue;
                    if(c==k){
                        if(distance[x][y] > distance[i][j]){
                            distance[x][y] = distance[i][j];
                            qq.push_front({x,y});
                        }    
                    }else{
                        if(distance[x][y] > distance[i][j] + 1){
                            distance[x][y] = distance[i][j] + 1;
                            qq.push_back({x,y});
                        }    
                    }
            }
        }
        return distance[n-1][m-1];
    }
};