class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        int vis[10000]={0};
        queue<pair<int,int>> qq;
        int fr[10000] = {0};
        for(int &i:forbidden) fr[i]=1;
        qq.push({0,0});
        int ans=0;
        
        while(qq.size()){
            int n = qq.size();
            
            for(int i=0;i<n;i++){
                int cur = qq.front().first;
                int back = qq.front().second;
                qq.pop();
                if(vis[cur] || cur>9999) continue;
                vis[cur]=1;
                if(cur==x) return ans;
                if(cur-b>=0 && fr[cur-b]==0 && back==0) qq.push({cur-b,1});
                if(cur+a<10000 && fr[cur+a]==0) qq.push({cur+a,0});      
                
            }
            ans++;
        }
        return -1;
        
        
        
    }
};