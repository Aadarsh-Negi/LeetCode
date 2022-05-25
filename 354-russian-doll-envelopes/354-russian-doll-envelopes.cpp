class Solution {
public:
    
    int maxEnvelopes(vector<vector<int>>& env) {
        sort(env.begin(),env.end(),[&](vector<int> &a,vector<int> &b){
            if(a[0]==b[0]) return a[1]>b[1];
            return a[0]<b[0];
        });
        // sort(env.begin(),env.end());
        
        set<int> S;
       for (auto &x : env){
           if(S.count(x[1])) continue;
            S.insert(x[1]);
            auto it = S.upper_bound(x[1]);
            if(it != S.end()) S.erase(it);
        }
        return S.size();
        
    }
};