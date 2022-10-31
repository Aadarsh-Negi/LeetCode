class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& mat) {
        bool ok = 1;
        
        for(int i=1;i<mat.size();i++)
            for(int j=1;j<mat[0].size();j++)
                ok&=(mat[i][j]==mat[i-1][j-1]);
          
        
        return ok;
    }
}; 