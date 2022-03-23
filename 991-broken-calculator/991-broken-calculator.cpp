class Solution {
public:
    int brokenCalc(int s, int t) {
        int ans=0;
       
        while(t>s){
            if(t&1) t++;
            else t/=2;
            ans++;
        }
        return ans + abs(s-t);
        
        
        
    }
};