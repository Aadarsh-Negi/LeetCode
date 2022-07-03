class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int n, int m, int r, int c) {
        vector<vector<int>> ans;
        
        int ln = r+1;
        int lm = c+1;
        int fn = r-1;
        int fm = c-1;
        
        auto ins = [&](int i,int j){
          if(i<0 || j<0 || i>=n || j>=m) return;
            ans.push_back({i,j});
        };
        // int t=10;
        while(ans.size() < n*m){
            while(c<=lm){
                ins(r,c);
                c++;
            }
            c--;
            r++;
            while(r<=ln){
                ins(r,c);
                r++;
            }
            r--;
            c--;
            
          
            
            while(c>=fm){
                ins(r,c);
                c--;
            }
            c++;
            r--;
              while(r>=fn){
                ins(r,c);
                r--;
            }
            r++;
            c++;
            ln++;
            lm++;
            fn--;
            fm--;
        }
        return ans;
    }
};