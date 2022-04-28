class Solution {
public:
    bool ok(int &x,int i,int j,vector<vector<int>> &vis,vector<vector<int>> &ht){
        vis[i][j]=1;
        if(i==ht.size()-1 && ht[0].size()-1 == j) return 1;
        if(i+1<ht.size()  && !vis[i+1][j] && abs(ht[i][j] - ht[i+1][j])<=x){
            if(ok(x,i+1,j,vis,ht)) return 1;
        }
        if(j+1<ht[0].size()  && !vis[i][j+1] && abs(ht[i][j] - ht[i][j+1])<=x){
            if(ok(x,i,j+1,vis,ht)) return 1;
        }
        if(i-1>=0 && !vis[i-1][j] && abs(ht[i][j] - ht[i-1][j])<=x){
            if(ok(x,i-1,j,vis,ht)) return 1;
        }
        if(j-1>=0 && !vis[i][j-1] &&  abs(ht[i][j] - ht[i][j-1])<=x){
            if(ok(x,i,j-1,vis,ht)) return 1;
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