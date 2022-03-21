class Solution {
public:
    int shortestBridge(vector<vector<int>>& gg) {
      
        int n=gg.size();
        
        function<void(int,int)> dfs = [&](int i,int j){
            
            if(i<0 || j<0 || j>=n || i>=n || gg[i][j]==0 || gg[i][j]==2) return;
            gg[i][j]=2;
            
            dfs(i+1,j);
            dfs(i,j-1);
            dfs(i-1,j);
            dfs(i,j+1);
            return;
        };
        bool ok=1;
    for(int i=0;i<n && ok;i++){
        for(int j=0;j<n;j++){
            if(gg[i][j]){
                dfs(i,j);
                ok=0;
                break;
            }
        }
    }
        queue<pair<int,int>> qq;
        for(int i=0;i<n;i++) 
            for(int j=0;j<n;j++) 
               if(gg[i][j]==2) qq.push({i,j});
        
        int ans=-1;
        while(qq.size()){
            int nq = qq.size();
            for(int k=0;k<nq;k++){
                int i = qq.front().first;
                int j = qq.front().second;
                qq.pop();
                
                if(i<0 || j<0 || j>=n || i>=n || gg[i][j]==-1) continue;
                if(gg[i][j]==1) return ans;
                
                gg[i][j]=-1;
                
                qq.push({i+1,j});
                qq.push({i,j-1});
                qq.push({i-1,j});
                qq.push({i,j+1});
            }
            ans++;
        }
        
        return ans;
    }
};