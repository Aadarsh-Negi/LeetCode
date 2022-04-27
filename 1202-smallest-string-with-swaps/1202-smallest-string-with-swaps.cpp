class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        vector<int> ar[100005];
        
        for(auto it:pairs){
            ar[it[0]].push_back(it[1]);
            ar[it[1]].push_back(it[0]);
        }
       int vis[100005]={0};
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
        
        // cout<<s<<">\n";
        for(int i=0;i<s.size();i++){
            
            if(!vis[i]) {
                dfs(i);
                if(cc.size()==0) continue;
                // for(int j:ind) cout<<j<<" ";
                // for(char c:cc) cout<<c<<"  ";
                auto it = cc.begin();
                for(int j:ind) {s[j] = *it; it++;}
                cc.clear();
                ind.clear();
                // cout<<s<<"<<";
            }
        }
        return s;
    }
};