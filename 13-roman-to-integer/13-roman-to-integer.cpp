class Solution {
public:
    int romanToInt(string s) {
        
        map<char,int> mp;
        
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;
        
        int n = s.size();
        
        int ans=0;
        
        
        // I 
        
        // cc c n=3
        //    2
        
        // I X X
        //
        
        
        
       for(int i=0;i<n;i++){
           char cur = s[i];
            if(i+1<n){
                char nxt = s[i+1];
                if(mp[cur] >= mp[nxt]){
                    ans+=mp[cur];
                }else{
                    ans+= (mp[nxt]-mp[cur]);
                    i++;
                }
            }else{
                ans+=mp[cur];
            }   
       }
        return ans;
        
    }
};