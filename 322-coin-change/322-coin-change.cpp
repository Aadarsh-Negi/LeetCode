
class Solution {
public:

    int coinChange(vector<int>& ar, int ss) {
        int ans=0;
        
        queue<long long> qq;
        qq.push(0);
        map<int,int> vis;
        while(qq.size()){
            int x = qq.size();
            for(int i=0;i<x;i++){
                long long ax = qq.front(); qq.pop();
                if(vis[ax]) continue;
                vis[ax]=1;
                if(ax==ss) return ans;
                for(int &i:ar)
                    if(i+ax<=ss) qq.push(i+ax);
            }
            ans++;
        }
        return -1;
        
    }
};