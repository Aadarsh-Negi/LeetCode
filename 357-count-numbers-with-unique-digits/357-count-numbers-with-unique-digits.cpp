class Solution {
public:
    int ans;
    
    void solve(int n,int fl=-1){
        if(n==0) {ans++; return;}
        for(int i=(fl==-1?1:0);i<=9;i++){
            if(vis[i]) continue;
            vis[i]=1;
            // cout<<i;
            solve(n-1,1);
            // cout<<"\n";
            vis[i]=0;
        }
    }
    
    vector<int> vis;
    int countNumbersWithUniqueDigits(int n) {
        ans=0;
        vis.resize(10,0);
            for(int i=0;i<=n;i++)
                    solve(i);
        // if(n>1) ans++;
        return ans;
  
    }
};