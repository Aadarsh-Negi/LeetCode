class Solution {
public:
    int convertTime(string cur, string last) {
       string vv;
        vv+=cur[0];
        vv+=cur[1];
        int v1 = stoi(vv);
        vv.clear();
        vv+=cur[3];
        vv+=cur[4];
        v1 = 60*v1 + stoi(vv);
        
        vv.clear();
        vv+=last[0];
        vv+=last[1];
        int v2 = stoi(vv);
        vv.clear();
        vv+=last[3];
        vv+=last[4];
        
        v2 = 60*v2 + stoi(vv);
        
        int diff = abs(v1-v2);
        int ans=0;
        // while(diff){
           ans+=diff/60; diff%=60;
            ans+=diff/15; diff%=15;
        ans+=diff/5; diff%=5;
        ans+=diff;
            
            // ans++;
        // }
        return ans;
        
        
        
        
        
    }
};