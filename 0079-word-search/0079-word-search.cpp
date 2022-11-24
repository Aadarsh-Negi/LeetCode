class Solution {
public:
    
    bool exist(vector<vector<char>>& b, string s) {
        
        auto ok = [&](auto &&ok,int i,int j,int k){
            if(k>=s.size()) return true;
            if(i<0 || j<0 || i>=b.size() || j>=b[0].size() || b[i][j]!=s[k]) return false;
            b[i][j]+=150;
            bool c = 0;
            c|=ok(ok,i,j+1,k+1);
            c|=ok(ok,i+1,j,k+1);
            c|=ok(ok,i,j-1,k+1);
            c|=ok(ok,i-1,j,k+1);
            b[i][j]-=150;
            return c;
        };
        
        for(int i=0;i<b.size();i++){
            for(int j=0;j<b[0].size();j++){
                if(s[0]==b[i][j]){
                    if(ok(ok,i,j,0)) return true;
                }
            }
        }
        return false;
    }
};