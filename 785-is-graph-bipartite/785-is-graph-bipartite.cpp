class Solution {
public:
    map<int,int> col;
    
    bool dfs(int i,int c,vector<vector<int>> &gg){
        col[i]  = c;
        
        
        bool ok=1;
        for(int x:gg[i]){
            if(col.count(x)==0){
                {ok&=dfs(x,c^1,gg);}    
            }else if(col[x] == col[i]) return 0;
        }
        return ok;
    }

    bool isBipartite(vector<vector<int>>& graph) {
         
        bool ok=1;
        for(int i=0;i<graph.size();i++) {if(col.count(i)==0) ok&=dfs(i,0,graph);}
        
        return ok;
        
    }
};