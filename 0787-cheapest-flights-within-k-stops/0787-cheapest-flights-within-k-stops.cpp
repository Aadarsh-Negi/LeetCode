class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto it:flights){
            int x = it[0];
            int y = it[1];
            int c = it[2];
            adj[x].push_back({y,c});
        }
        vector<int> dis(n,INT_MAX);
        queue<int> qq;
        qq.push(src);
        dis[src] = 0;
        while(qq.size() && k-->=0){
            int sz =  qq.size();
            vector<int> temp(dis);
            while(sz--){
                int cur = qq.front(); qq.pop();
                for(auto &[a,b]:adj[cur]){
                    if(dis[a] > temp[cur] + b){
                        dis[a] = temp[cur] + b;
                        qq.push(a);
                    }
                }
            }
        }
        return dis[dst]==INT_MAX ? -1 : dis[dst];
    }
};