class Solution {
public:
    vector<long long> bin(long long n){
        vector<long long> res;
        
        for(int i=0;i<31;i++){
            if(n&(1LL<<i)){
                res.push_back(1LL<<i);
            }
        }
        
        return res;
    }
    vector<int> productQueries(int n, vector<vector<int>>& qq) {
        vector<int> ans;
        
        vector<long long> pp = bin(n);
        
        long long const mod = 1e9 + 7;
        for(auto it:qq){
            int l = it[0];
            int r = it[1];
            
            long long cur = 1;
           
            for(int i=l;i<=r;i++){
                cur*=pp[i];
                cur%=mod;
            }
                
            ans.push_back(cur);
        }
        
        return ans;
        
    }
};