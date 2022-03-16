class Solution {
public:
    bool validateStackSequences(vector<int>& p, vector<int>& tar) {
        int n = p.size();
        
        int i=0;
        int j=0;
        
        
        
        while(i<n && j<n){
            
            if(i>=0 && tar[j]==p[i]){
                p[i]=-1;
                j++;
                while(i>=0 && p[i]==-1) i--;
                
            
            }else i++;

        }
        
        return j==tar.size();
        
        
        
        
        
        
    }
};