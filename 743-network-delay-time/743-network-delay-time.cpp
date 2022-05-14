class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> gg(n+2);
        
        for(vector<int> &it:times){
            int u = it[0];
            int v = it[1];
            int w = it[2];
            gg[u].push_back({v,w});
        }
        
        queue<int> qq;
        qq.push(k);
        int ans=0;
        vector<int> dis(n+1,1e9);
        dis[0]=0;
        dis[k]=0;
        while(qq.size()){
            int n = qq.size();
            for(int i=0;i<n;i++){
                int x = qq.front();
                qq.pop();
                
                for(auto &[v,w]:gg[x]){
                    int temp = dis[v];
                    dis[v] = min(dis[v],w + dis[x]);
                    if(temp==dis[v]) continue;
                    qq.push(v);
                }
            }
        }
        ans = *max_element(dis.begin(),dis.end());
        return ans==1e9?-1:ans;
        
    }
};