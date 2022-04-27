class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        map<int,vector<int>> ar;
        
        for(auto it:pairs){
            ar[it[0]].push_back(it[1]);
            ar[it[1]].push_back(it[0]);
        }
       unordered_map<int,int> vis;
        vector<int> ind;
        vector<char> cc;
        function<void(int)> dfs = [&](int i){
            vis[i]=1;
            ind.push_back(i);
            cc.push_back(s[i]);
            
            for(int j:ar[i]){
                if(!vis[j]){
                    dfs(j);
                }
            } 
            return;
        };
        
        for(int i=0;i<s.size();i++){
            if(!vis[i]) {
                dfs(i);
                sort(ind.begin(),ind.end());
                sort(cc.begin(),cc.end());
                int k=0;
                for(int &j:ind) s[j] = cc[k++];
                cc.clear();
                ind.clear();
                
            }
        }
        return s;
    }
};