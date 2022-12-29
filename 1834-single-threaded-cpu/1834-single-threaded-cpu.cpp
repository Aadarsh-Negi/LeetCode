class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        vector<int> idx(n);
        iota(idx.begin(),idx.end(),0);
        sort(idx.begin(),idx.end(),[&](int& a,int &b){
            if(tasks[a][0] == tasks[b][0]) return tasks[a][1] < tasks[b][1];
            return tasks[a][0] < tasks[b][0];
        });
        
        vector<int> ans;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> qq;
        int i=0;
        int cur = 0;
        // ans.push_back(idx[0]);
        while(i<n || qq.size()){
            // cout<<cur<<" "<<i<<"< ";
          
            while(i<n && cur>=tasks[idx[i]][0]) qq.push({tasks[idx[i]][1],idx[i]}),i++;
            // cout<<i<<"\n";
            if(qq.size()) cur=min((int)1e9,cur+qq.top().first),ans.push_back(qq.top().second),qq.pop();            
            if(i<n && qq.size()==0 && cur<tasks[idx[i]][0]) cur = tasks[idx[i]][0];
        }
        
        
        return ans;
        
    }
};