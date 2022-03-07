class Solution {
public:
    unordered_map<int,int> cord;
    int last;
    map<pair<int,int>,int> dp;
    bool solve(int i=0,int k=1){
        
        if(cord[i+k]==0 || k<=0) return 0;
        
        if(i+k == last) return 1;
        
        if(dp.count({i,k})) return dp[{i,k}];
        
        return dp[{i,k}] = solve(i+k,k) || solve(i+k,k-1) || solve(i+k,k+1);
        
//         // if(cord.count(i)==0) return 0;
//         if(i==last) return 1;
//         if(i>last || i<0 ) return 0;
//         if(dp.count({i,k})>0) return dp[{i,k}];
//         bool ok=0;
        
//         if(cord.count(i+k)){
            
//             ok|=solve(i+k,k);
//             // dp[i][k]=ok;
            
//         }
//         if(cord.count(i+k+1)){
            
//             ok|=solve(i+k-1,k-1);
//             // dp[i][k]=ok;
            
//         }
//         if(k-1>0 && cord.count(i+k-1)){
            
//             ok|=solve(i+k+1,k+1);
//             // dp[i][k]=ok;
            
//         }
//         return dp[{i,k}] = ok;
    
    }
    
    
    bool canCross(vector<int>& stones) {
        for(int &i:stones) cord[i]=1;
            last = stones.back();
        
        
        return solve();
        
    }
};