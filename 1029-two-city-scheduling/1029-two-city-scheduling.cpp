class Solution {
public:
    map<pair<int,int>,int> dp;
    vector<vector<int>> cc;
    int solve(int i,int a,int b){
        if(i>=cc.size()) return 0;
        
        if(dp.count({a,b})) return dp[{a,b}];
        
        int temp = INT_MAX;
        
        if(a){
            temp =min(temp,cc[i][0] + solve(i+1,a-1,b));
        }
        
        if(b){
            temp =min(temp,cc[i][1] + solve(i+1,a,b-1));
        }
        
        
        return dp[{a,b}]=temp;
    }
    
    
    int twoCitySchedCost(vector<vector<int>>& costs) {
        cc=costs;
        int a = costs.size()/2;
         
        return solve(0,a,a);
    }
};