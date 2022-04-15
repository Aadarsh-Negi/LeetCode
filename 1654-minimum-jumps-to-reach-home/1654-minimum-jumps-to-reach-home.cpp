class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        map<int,int> vis;
        queue<pair<int,int>> qq;
        set<int> fr;
        for(int &i:forbidden) fr.insert(i);
        qq.push({0,0});
        int ans=0;
        
        while(qq.size()){
            int n = qq.size();
            
            for(int i=0;i<n;i++){
                int cur = qq.front().first;
                int back = qq.front().second;
                qq.pop();
                if(vis[cur] || cur>9999 || cur<-9999) continue;
                vis[cur]=1;
                if(cur==x) return ans;
                if(fr.count(cur-b)==0 && back==0 && cur-b>=0) qq.push({cur-b,1});
                if(fr.count(cur+a)==0) qq.push({cur+a,0});      
                
            }
            ans++;
        }
        return -1;
        
        
        
    }
};