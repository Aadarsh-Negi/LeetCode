class Solution {
public:
    
    
    
    
    bool isBipartite(vector<vector<int>>&g) {
        int n = g.size();
        vector<int> col(n+3,-1);
        auto bfs = [&](int src){
          queue<int> qq;
          qq.push(src);
            
          while(qq.size()){
              
              int cur = qq.front(); qq.pop();
              if(col[cur]==-1) col[cur]=1;
              
              for(int i:g[cur]){
                  if(col[i]==-1){
                      col[i] = col[cur]^1;
                      qq.push(i);
                  }else if(col[cur]==col[i]) return 0;
              }
          }
            return 1;
        };
        
        bool ok=1;
        for(int i=0;i<n;i++) if(col[i]==-1) ok&=bfs(i);
        
        return ok;
        
        
    }
};