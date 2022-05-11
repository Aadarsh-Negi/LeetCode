class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<int> dis(n,INT_MAX);
        dis[src]=0;
        for(int i=0;i<=k;i++){
            vector<int> temp = dis;
            for(int i=0;i<flights.size();i++){
                if(temp[flights[i][0]]!=INT_MAX) 
                    dis[flights[i][1]] = min(dis[flights[i][1]],temp[flights[i][0]]+flights[i][2]);

            }
            
        }
        if(dis[dst]==INT_MAX) return -1;
        return dis[dst];
    
    }
};