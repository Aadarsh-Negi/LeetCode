class Solution {
public:
    void gameOfLife(vector<vector<int>>& bb) {
        int n = bb.size();
        int m = bb[0].size();
        
        vector<vector<int>> ans = bb;
        
        vector<int> dir_x = {-1,1,-1,1,0,0,1,-1};
        vector<int> dir_y = {-1,1,1,-1,1,-1,0,0};
        
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int liv=0;
                for(int k=0;k<8;k++){
                    int cx = dir_x[k] + i;
                    int cy = dir_y[k] + j;
                    if(cy<0 || cx<0 || cx>=n || cy>=m) continue;
                    if(bb[cx][cy]) liv++;
                }
                if(bb[i][j]){
                    if(liv<2) ans[i][j]=0;
                    else if(liv>3) ans[i][j]=0;
                }else{
                    if(liv==3) ans[i][j]=1;
                }
            }
        }
        
        bb=ans;
        
    }
};