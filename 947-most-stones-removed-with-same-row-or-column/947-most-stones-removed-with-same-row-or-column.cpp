class Solution {
public:
    int find(int x,vector<int> &par){
        if(par[x]<=-1) return x;
        return par[x] = find(par[x],par);
    }
    int removeStones(vector<vector<int>>& st) {
        const int N = 1e4 + 10;
       
        vector<int> par(N,-1);
        
        for(int i=0;i<st.size();i++){
            for(int j=i+1;j<st.size();j++){
                if(st[i][0]==st[j][0] || st[j][1]==st[i][1]){
                    int x = find(i,par);
                    int y = find(j,par);
                    if(x==y) continue;
                    par[x]+=par[y];
                    par[y] = x;
                }
            }
        }
        
        int ans = 0;
        
        for(int i=0;i<N;i++) if(par[i]<-1) ans+=abs(par[i])-1;
       
        return ans;
        
    }
};