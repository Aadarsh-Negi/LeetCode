class Solution {
public:
    vector<vector<int>> dp;
    
    int solve(int i,int a,int b,vector<vector<int>> &cc){
        if(i>=cc.size()) return 0;
        
        if(dp[a][b]!=-1) return dp[a][b];
        
        int temp = INT_MAX;
        
        if(a){
            temp =min(temp,cc[i][0] + solve(i+1,a-1,b,cc));
        }
        
        if(b){
            temp =min(temp,cc[i][1] + solve(i+1,a,b-1,cc));
        }
        
        
        return dp[a][b]=temp;
    }
    
    
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int a = costs.size()/2;
        dp.resize(a+1);
        for(auto &i:dp) i.resize(a+1),fill(i.begin(),i.end(),-1);
        
        return solve(0,a,a,costs);
    }
};