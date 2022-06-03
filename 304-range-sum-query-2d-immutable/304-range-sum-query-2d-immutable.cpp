class NumMatrix {
public:
      int sum[1000][1000];
    NumMatrix(vector<vector<int>>& matrix) {

  for(int i=0;i<=matrix.size();i++)
  {
    for(int j=0;j<=matrix[0].size();j++)
    {
        if(i==0 || j==0) {sum[i][j]=0; continue;}
      sum[i][j]= sum[i-1][j]+sum[i][j-1]+matrix[i-1][j-1]-sum[i-1][j-1];
    }

  } 
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        row1++;
        row2++;
        col1++;
        col2++;
        return sum[row2][col2]+sum[row1-1][col1-1]-sum[row1-1][col2]-sum[row2][col1-1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */