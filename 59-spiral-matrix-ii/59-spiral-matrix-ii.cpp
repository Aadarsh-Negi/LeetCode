class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
     
        vector<vector<int>> ans(n,vector<int>(n));
         // vector<pair<int,int>> turn = {{0,1},{1,0},{0,-1},{-1,0}};
        
        
        int num=1;
        
        int i=0;
        int j=0;
        
        int ls = n;
        int fs = 0;
        
        while(num<=n*n){
            while(j<ls) ans[i][j++]=num++;
            // ls--;
            j--;
            i++;
            while(i<ls) ans[i++][j]=num++;
            i--;
            ls--;
            j--;
            
            while(j>=fs) ans[i][j--]=num++;
            j++;
            i--;
            while(i>fs) ans[i--][j]=num++;
            i++;
            j++;
            fs++;
        }
        return ans;
        
        
        
    }
};