class Solution {
public:
int solve(vector<vector<int>>& a, int i ,int j,int n ,int m){
      int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
      int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
       int cnt = 0;
      for(int k = 0; k<8; k++) {
         int x = i+dx[k];
         int y = j+dy[k];
          if(x<0 or x>=n) continue;
          if(y<0 or y>=m) continue;
          cnt+=a[x][y];
      }
      return cnt;
  }
    void gameOfLife(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();
        vector<vector<int>>ans(n,vector<int>(m));
        for(int i = 0; i<n; i++) {
           for(int j = 0; j<m; j++) {
             
             int live = solve(a,i,j,n,m);
             
             if(  a[i][j] == 1 and live < 2) {
               ans[i][j] = 0;
             }
              else if(a[i][j] == 1 and live == 2 or live == 3){
                ans[i][j] = 1;
              }
              else if(a[i][j] == 1 and live > 3){
                ans[i][j] = 0;
              }
              else if(a[i][j] == 0 and live == 3){
                ans[i][j] = 1;
              }
           }
        }
       a = ans;
      return;
    }
};