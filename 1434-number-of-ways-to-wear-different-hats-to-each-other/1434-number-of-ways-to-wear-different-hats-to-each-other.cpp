const int mod = 1e9 + 7;
class Solution {
public:
    map<pair<int,int>,int> dp;
    int n;
    int solve(int h,int mask,vector<vector<int>> &hx){
        if(mask==(1<<n)-1) return 1;
        if(h>40) return 0;
        if(dp.count({mask,h})) return dp[{mask,h}];
        
        int temp = solve(h+1,mask,hx);
        
        for(int i=0;i<hx[h].size();i++){
            int v = hx[h][i];
            if((mask&(1<<v))==0){
                temp+=solve(h+1,mask|(1<<v),hx);
                temp%=mod;
            }
        }
        return dp[{mask,h}] = temp;
        
    }
    
    int numberWays(vector<vector<int>>& hats) {
        // all = (1<<hats.size())-1;
        vector<vector<int>> hx(45);
        for(int i=0;i<hats.size();i++){
            for(int j=0;j<hats[i].size();j++){
                hx[hats[i][j]].push_back(i);
            }
        }
        n=hats.size();
        return solve(1,0,hx);   
    }
};