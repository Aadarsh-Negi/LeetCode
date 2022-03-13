class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        vector<int> ans;
        int i,j,n,m,s1,s2;
        s1=s2=i=j=0;
        n=mat.size();
        m=mat[0].size();
        
        
        
        int c=n*m;
        while(c){
            
            
            while(j<m && c) ans.push_back(mat[i][j++]),c--;
            j--;
            i++;
            
            while(i<n && c) ans.push_back(mat[i++][j]),c--;
            i--;
            j--;
            
            while(j>=s1 && c) ans.push_back(mat[i][j--]),c--;
            j++;
            i--;
            
            while(i>s2 && c) ans.push_back(mat[i--][j]),c--;
            i++;
            j++;
            
            s1++;
            s2++;
            n--;
            m--;
            
        }
        return ans;
        
        
        
        
    }
};