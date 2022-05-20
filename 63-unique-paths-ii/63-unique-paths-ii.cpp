class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obs) {
        // int const mod = 1e9 + 7;
        
        for(int i=0;i<obs.size();i++) for(int j=0;j<obs[0].size();j++) obs[i][j]=obs[i][j]==1?-1:0;
        
        if(obs[0][0] || obs.back().back()) return 0;
        
        for(int i=0;i<obs.size();i++) {if(obs[i][0]==0) obs[i][0]=1; else break;}
        
        for(int i=1;i<obs[0].size();i++) {if(obs[0][i]==0) obs[0][i]=1; else break;}
        // obs[0][0]=0;
        for(int i=0;i<obs.size();i++) {if(obs[i][0]==-1) obs[i][0]=0; }
        for(int i=0;i<obs[0].size();i++) {if(obs[0][i]==-1) obs[0][i]=0;}
        
        
        
        for(int i=1;i<obs.size();i++){
            for(int j=1;j<obs[0].size();j++){
                if(obs[i][j]==-1) obs[i][j]=0;
                else{
                    obs[i][j]+=obs[i-1][j];
                    // obs[i][j]%=mod;
                    obs[i][j]+=obs[i][j-1];
                    // obs[i][j]%=mod;
                }
            }
        }
        return obs.back().back();
        
    }
};