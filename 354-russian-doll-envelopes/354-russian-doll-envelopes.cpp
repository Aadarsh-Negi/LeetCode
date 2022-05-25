class Solution {
public:
    
    int maxEnvelopes(vector<vector<int>>& env) {
        sort(env.begin(),env.end(),[&](vector<int> &a,vector<int> &b){
            if(a[0]==b[0]) return a[1]>b[1];
            return a[0]<b[0];
        });
        // sort(env.begin(),env.end());
        // vector<int> v;
// for (int i = 0; i < n; i++) {
    
//     auto it = lower_bound(v.begin(), v.end(), a[i]);
//     if (it != v.end()) *it = a[i];
//     else v.push_back(a[i]);

        vector<int> S;
       for (auto &x : env){
            auto it = lower_bound(S.begin(),S.end(),x[1]);
            if(it != S.end()) *it=x[1];
            else S.push_back(x[1]);
        }
        return S.size();
        
    }
};