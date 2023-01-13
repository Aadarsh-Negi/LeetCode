class Solution {
public:
    vector<vector<int>> gg;
    int ans;
    int solve(int u,string &s){
        vector<int> sub(2,0);
        
        for(int i:gg[u]){
            int x = solve(i,s);
            if(s[u]==s[i])  continue;
            sub.push_back(x);
            sort(sub.rbegin(),sub.rend());
            sub.pop_back();
        }
        ans=max(ans,sub[0]+sub[1]+1); 
        return sub[0]+1;
    }
    
    int longestPath(vector<int>& par, string s) {
        gg.resize(par.size()+10);
        
        ans=0;
        for(int i=1;i<par.size();i++) gg[par[i]].push_back(i);
        
        solve(0,s);
        return ans;
    }
};