class Solution {
public:
    
   
    string intToRoman(int n) {
        
        vector<int> val = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
        vector<string> ch = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
        
        
        string ans;
        while(n>0){
            
            for(int i=val.size()-1;i>=0;i--){
                if(val[i]<=n){
                    ans+=ch[i];
                    n-=val[i];
                    break;
                }   
            
            }
        }
        return ans;
        
        
        
        
    }
};