class Solution {
public:
    int solve(int n,int fl=-1){
        if(n==0) {return 1;}
        int temp=0;
        for(int i=(fl==-1?1:0);i<=9;i++){
            if(vis[i]) continue;
            vis[i]=1;
            temp+=solve(n-1,1);
            vis[i]=0;
        }
        return temp;
    }
    
    vector<int> vis;
    int countNumbersWithUniqueDigits(int n) {
        int ans=0;
        vis.resize(10,0);
            while(n!=-1) ans+=solve(n),n--;
        return ans;
  
    }
};