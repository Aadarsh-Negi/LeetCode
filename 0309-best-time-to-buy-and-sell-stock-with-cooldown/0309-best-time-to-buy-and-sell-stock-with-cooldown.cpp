int const N = 5e3 + 44;
int dp[N];
class Solution {
public:
    int solve(vector<int> &p,int i=0){
        if( i >= p.size()) return 0;
        if(dp[i] != -1) return dp[i];
        
        int temp = solve(p,i+1);
        
        for(int j = i + 1; j < p.size() ; j++){
            temp = max(temp,p[j] - p[i] + solve(p,j+2));
        }
        return dp[i] = temp;
        
    }
    int maxProfit(vector<int>& p) {
        memset(dp,-1,sizeof(dp));
        return solve(p);
    }
};


      //      1
      //    /  \
      //    2  2x
      //   /   \
      // 3x     3
      //         \ 
      //          0x
      //          / \ 
      //         2x   2
      //          \   \ 
      //          3    1