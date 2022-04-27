class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        map<int,vector<int>> ar;
        
        for(auto it:pairs){
            ar[it[0]].push_back(it[1]);
            ar[it[1]].push_back(it[0]);
        }
       unordered_map<int,int> vis;
        // string ans;
        set<int> ind;
        multiset<char> cc;
        function<void(int)> dfs = [&](int i){
            vis[i]=1;
            ind.insert(i);
            cc.insert(s[i]);
            
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
                auto it = cc.begin();
                for(int j:ind) {s[j] = *it; it++;}
                cc.clear();
                ind.clear();
                
            }
        }
        return s;
    }
};