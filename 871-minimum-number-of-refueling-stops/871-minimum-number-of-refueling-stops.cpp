// #define ll long long
// ll dp[505][505];
class Solution {
public:
    
//     ll solve(int i,int j,ll f,vector<vector<int>> &sx){
//         if(i>=sx.size()) return 0;
        
//         if(dp[i][j]!=-1) return dp[i][j];
        
//         ll temp = LLONG_MAX/2;
//         for(int k=i;k<sx.size();k++){
//             ll use = sx[k][0] - sx[j][0];
//             if(use<=f)
//                 temp = min(temp,solve(k+1,k,f-use,sx));
//             if(use<=f+sx[j][1])
//                 temp = min(temp,1+solve(k+1,k,f-use+sx[j][1],sx));
//         }
        
//         return dp[i][j] = temp;
//     }

    int minRefuelStops(int tar, int cur, vector<vector<int>>& sx) {
        
        int ans=0;
        priority_queue<int> qq;
        int i=0;
        while(cur < tar){
            while(i<sx.size() && sx[i][0]<=cur) qq.push(sx[i++][1]);
            
            if(qq.size()==0) return -1;
            ans++;
            cur+=qq.top(); qq.pop();
        }
        return ans;
        // sx.insert(sx.begin(),{0,0});
        // sx.push_back({tar,0});
        // memset(dp,-1,sizeof(dp));
        // int ans = solve(1,0,cur,sx);
        // if(ans>=LLONG_MAX/2) ans=-1;
        // return ans;
    }
};