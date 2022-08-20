class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& q) {
        const int n = s.size();
        vector<int> rr(n+5,0);
        
        for(auto it:q){
            int l = it[0];
            int r = it[1];
            int v = (it[2] ? 1:-1);
            rr[l]+=v;
            rr[r+1]-=v;
        }
        
        for(int i=1;i<=n;i++) rr[i]+=rr[i-1];
        
        for(int i=0;i<n;i++){
            int x = s[i]-'a';
            x+=rr[i];
            while(x<0) x+=26;
            x%=26;
            s[i] = 'a' + x;
        }
        return s;
        
        
        
        
    }
};