int dp[20][20][2];
class Solution {
public:
    string mx;
    
    int solve(int i,int fl=0,int cnt=0){
        
        if(i>=mx.size()) return cnt;
        if(dp[i][cnt][fl]!=-1) return dp[i][cnt][fl];
        
        int temp=0;
        for(int j=0;j<10;j++){
            int v = mx[i]-'0';
            if(fl){
                temp+=solve(i+1,fl,cnt+(j==1));
            }
            else if(v >= j){
                temp+=solve(i+1,v>j,cnt+(j==1));
            }
        }
        return dp[i][cnt][fl] = temp;
        
    }
    
    int countDigitOne(int n) {
       memset(dp,-1,sizeof(dp));
       mx = to_string(n);
      return solve(0);
        
    }
};
// 1 2 3 4 5 6 7 8 9 10 11 12 13
