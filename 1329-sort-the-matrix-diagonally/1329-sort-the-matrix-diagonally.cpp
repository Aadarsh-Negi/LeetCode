class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        for(int i=0;i<n;i++){
            int x = i;
            int y = 0;
            vector<int> temp;
            while(x<n && y<m) temp.push_back(mat[x++][y++]);
            sort(temp.begin(),temp.end());
            x = i;
            y = 0;
            int l=0;
            while(x<n && y<m) mat[x++][y++]=temp[l++];
        }
        for(int i=0;i<m;i++){
            int x = 0;
            int y = i;
            vector<int> temp;
            while(x<n && y<m) temp.push_back(mat[x++][y++]);
            sort(temp.begin(),temp.end());
            x = 0;
            y = i;
            int l=0;
            while(x<n && y<m) mat[x++][y++]=temp[l++];
        }
        return mat;
    }
};