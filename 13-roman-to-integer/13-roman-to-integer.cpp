class Solution {
public:
    
    int val(char c){
        if(c=='I') return 1;
        if(c=='V') return 5;
        if(c=='X') return 10;
        if(c=='L') return 50;
        if(c=='C') return 100;
        if(c=='D') return 500;
        return 1000;
    }
    
    int romanToInt(string s) {
      
        
        int n = s.size();
        
        int ans=0;
        

        
        
       for(int i=0;i<n;i++){
           char cur = s[i];
            if(i+1<n){
                char nxt = s[i+1];
                if(val(cur) >= val(nxt)){
                    ans+=val(cur);
                }else{
                    ans+= (val(nxt)-val(cur));
                    i++;
                }
            }else{
                ans+=val(cur);
            }   
       }
        return ans;
        
    }
};