class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
         vector<long long> par(n+10,-1);
    
    function<long long(long long)> find = [&](long long x){
        if(par[x]<=-1) return x;
        return par[x] = find(par[x]);
    };
    
    
        for(auto it:edges){
            long long ux = find(it[0]);
            long long ix = find(it[1]);
                if(ix!=ux){
                    par[ix]+=par[ux];
                    par[ux]=ix;
                }
        }
   
    long long ans=0;
       vector<long long> val;
        for(int i=0;i<n;i++){
            if(par[i]<=-1) val.push_back(abs(par[i]));
        }
        // for(long long i:val) cout<<i<< " ";
        for(int i=0;i<val.size();i++){
            // for(int j=i+1;j<val.size();j++){
                ans+=val[i]*(n-val[i]);
            // }
        }
        return ans/2;
    }
};