class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int ans=s.size();
        
        int z = 0;
        for(char &c:s)
            z+=c=='0';
        
        for(char &c:s){
            z-=c=='0';
            ans=min(ans,z);
            z+=c=='1';
        }
        return ans;
        
 
        
        return ans;
        
    }
};