int dir_x[] = {1,-1,0,0};
int dir_y[] = {0,0,1,-1};
class Solution {
public:
    bool ok(int &ans,int i,int j,vector<vector<int>> &vis,vector<vector<int>> &ht){
        vis[i][j]=1;
        if(i==ht.size()-1 && ht[0].size()-1 == j) return 1;
        
        for(int k=0;k<4;k++){
            int x = dir_x[k] + i;
            int y = dir_y[k] + j;
            if(y<0 || x<0 || x>=ht.size() || y>=ht[0].size() || vis[x][y] || abs(ht[i][j] - ht[x][y])>ans) continue;
            
            if(ok(ans,x,y,vis,ht)) return 1;
            
        }
        
        return 0;
        
    }
    
    int minimumEffortPath(vector<vector<int>>& ht) {
        
        int l = 0;
        int r = 1e6+3;  
        while(l<r){
            
            int mid = l + (r-l)/2;
            vector<vector<int>> vis(ht.size(),vector<int>(ht[0].size(),0));
            if(ok(mid,0,0,vis,ht)){
                r = mid;
            }else l = mid+1;    
        }
        return r;
        
    }
};