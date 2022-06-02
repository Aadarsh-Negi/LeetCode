class Solution {
public:
    int ans;
    
    void solve(int n,int fl=-1){
        if(n==0) {ans++; return;}
        
        for(int i=(fl==-1?1:0);i<=9;i++){
            if(vis[i]) continue;
            vis[i]=1;
            solve(n-1,1);
            vis[i]=0;
        }
    }
    
    vector<int> vis;
    int countNumbersWithUniqueDigits(int n) {
        ans=(n>0?10:1);
        
            for(int i=2;i<=n;i++)
                    vis.resize(10,0),solve(i);
        // if(n>1) ans++;
        return ans;
  
    }
};