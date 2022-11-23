class Solution {
public:
    
    bool ok(int i,int j,vector<vector<char>> & bb){
        if(bb[i][j]=='.') return 1;
        
        char cur = bb[i][j];
        
        for(int k=i+1;k<9;k++) if(bb[k][j]==cur) return 0;
        for(int k=i-1;k>=0;k--) if(bb[k][j]==cur) return 0;
        
        for(int k=j+1;k<9;k++) if(bb[i][k]==cur) return 0;
        for(int k=j-1;k>=0;k--) if(bb[i][k]==cur) return 0;
        
        int row = 3 * (i/3);
        int col = 3 * (j/3);
        
        for(int t=row;t<row+3;t++){
            for(int t2=col;t2<col+3;t2++){
                if(t!=i && t2!=j && cur==bb[t][t2]) return 0;
            }
        }
        
        return 1;
        
    }
    
    
    
    bool isValidSudoku(vector<vector<char>>& gg) {
        
        
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(!ok(i,j,gg)) return 0;
            }
        }
        
        return 1;
        
        
        
        
    }
};