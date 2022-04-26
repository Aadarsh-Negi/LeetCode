class Solution {
public:
    vector<int> par;
    // vector<int> par2;
    int find(int x){
        if(par[x]==-1) return x;
        return par[x] = find(par[x]);
    }
    
    void comb(int x,int y){
        par[x] = y;
    }
//     int find(int x){
//         if(par2[x]==-1) return x;
//         return par2[x] = find(par2[x]);
//     }
    
//     void comb(int x,int y){
//         par2[x] = y;
//     }
    
    int minCostConnectPoints(vector<vector<int>>& p) {
        par.resize(1e6+1);
        // par2.resize(1e6+1);
        // fill(par2.begin(),par2.end(),-1);
        fill(par.begin(),par.end(),-1);
        
        
        vector<pair<int,pair<int,int>>> mx;
        for(int i=0;i<p.size();i++){
            for(int j=i+1;j<p.size();j++){
                int dis = abs(p[i][0] - p[j][0]) + abs(p[i][1] - p[j][1]);
                mx.push_back({dis,{i,j}});
            }
        }
        
        sort(mx.begin(),mx.end());
        int wt=0;
        for(int i=0;i<mx.size();i++){
            int x = find(mx[i].second.first);
            int y = find(mx[i].second.second);
            if(x==y) continue;
            comb(x,y);
            wt+=mx[i].first;
        }
        return wt;
    }
};