class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& ht) {
        priority_queue<pair<int,pair<int,int>>> qq;
        
        qq.push({0,{0,0}});
        // int ans=1e8;
        
        int dir_x[] = {0,0,-1,1};
        int dir_y[] = {-1,1,0,0};
        
        vector<vector<int>> ans(ht.size(),vector<int>(ht[0].size(),INT_MAX));
        ans[0][0]=0;
        while(qq.size()){
            
            int i = qq.top().second.first;
            int j = qq.top().second.second;
            int xx = -qq.top().first;
            if(i==ht.size()-1  && j==ht[0].size()-1) return xx;
            qq.pop();
            for(int k=0;k<4;k++){
                int x = i+dir_x[k];
                int y = j+dir_y[k];
                
                if(x<0 || y<0 || x>=ht.size() || y>=ht[0].size()) continue;
                
                int mx = max(xx,abs(ht[i][j] - ht[x][y]));
                
                if(ans[x][y]>mx){
                    ans[x][y] = mx;
                    qq.push({-mx,{x,y}});
                }
                
            }
            
        }
        return ans[ht.size()-1][ht[0].size()-1];
        
        
    }
};