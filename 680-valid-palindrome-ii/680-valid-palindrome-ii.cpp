class Solution {
public:
    bool validPalindrome(string s) {
      for(int k=0;k<2;k++){
            int i=0;
            int j=s.size()-1;
            int op=1;
            while(i<j){
                if(s[i]!=s[j]){
                    op--;
                    if(op<0){
                        op=-1;
                        break;
                    }else i++;
                }else 
                    i++,j--;
            }
            if(op!=-1) return 1;  
        reverse(s.begin(),s.end());
      }  
        
    
    return 0;    
        
    }
};