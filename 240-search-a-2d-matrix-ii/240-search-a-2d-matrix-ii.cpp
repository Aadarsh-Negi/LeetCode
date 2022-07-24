class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int x) {
        int i=0;
     int j=mat[0].size()-1;
     while (i < mat.size() && j >= 0)
    {
        if (mat[i][j] == x)
        {
            return 1;
        }
        if (mat[i][j] > x)
            j--;
       
        // Check if mat[i][j] < x
        else
            i++;
    }
     return 0;
    }
};