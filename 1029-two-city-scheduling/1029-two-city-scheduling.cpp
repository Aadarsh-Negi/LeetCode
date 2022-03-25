class Solution {
public:
    map<pair<int,pair<int,int>>,int> dp;
    vector<vector<int>> cc;
    int solve(int i,int a,int b){
        if(i>=cc.size()) return 0;
        
        if(dp[{i,{a,b}}]) return dp[{i,{a,b}}];
        
        int temp = INT_MAX;
        if(a){
            temp = min(temp,cc[i][0] + solve(i+1,a-1,b));
        }
        
        if(b){
            temp = min(temp,cc[i][1] + solve(i+1,a,b-1));
        }
        
        return dp[{i,{a,b}}]=temp;
        
    }
    
    
    int twoCitySchedCost(vector<vector<int>>& costs) {
        cc=costs;
        int a = costs.size()/2;
        int b = a;
        
        
        
        return solve(0,a,b);
        
        
        
    }
};