class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& g) {
        int ans=0;
        int cnt=0;
        
        function<void(int,int)> dfs = [&](int i,int j){
            if(i<0 || j<0 || i>=g.size() || j>=g[0].size() || g[i][j]==0) return;
            
            cnt++;
            g[i][j]=0;
            dfs(i+1,j);
            dfs(i-1,j);
            dfs(i,j-1);
            dfs(i,j+1);
            
        };
        
        for(int i=0;i<g.size();i++){
            for(int j=0;j<g[0].size();j++){
                cnt=0;
                dfs(i,j);
                ans=max(ans,cnt);
            }
        }
        return ans;
        
    }
};