class Solution {
public:
    int find(int x,vector<int> &par){
        if(par[x]==-1) return x;
        return par[x] = find(par[x],par);
    }
    int removeStones(vector<vector<int>>& st) {
        const int N = 5e5 + 10;
        int px = 1e5;
        vector<int> par(N,-1);
       // int n = st.size();
        for(vector<int> &ax:st){ // 
            int x = find(ax[0],par);
            int y = find(px+ax[1],par);
            if(x==y) continue;
            // par[x]+=par[y];
            par[x] = y;
        }
        set<int> sx;
        for(vector<int> &ax:st){ // 
            int x = find(ax[0],par);
            sx.insert(x);
        }
        
        
        
        int ans=st.size()-sx.size();
        
        
        
        return ans;
        
    }
};