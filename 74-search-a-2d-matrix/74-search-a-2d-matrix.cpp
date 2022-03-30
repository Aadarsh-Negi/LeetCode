class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int tar) {
        int i=0;
        int i2=mat.size()-1;

        while(i<=i2){
            
            int mid = i + (i2-i)/2;
            
            if(mat[mid][0]==tar || mat[mid][mat[0].size()-1]==tar) return 1;
            
            if(mat[mid][0]<=tar && mat[mid][mat[0].size()-1]>=tar){
                int j=0;
                int j2=mat[0].size()-1;
                while(j<=j2){
    
                    int mid2 = j + (j2-j)/2;
                    
                    if(mat[mid][mid2]==tar) return 1;
                    else if(mat[mid][mid2]>tar) j2=mid2-1;
                    else j=mid2+1;
                    
                }
                return 0;
 
            }else{
                
                if(mat[mid][0]<tar) i=mid+1;
                else i2=mid-1;
                
            }

        }
        return 0;
        
        
    }
};