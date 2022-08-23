#define ll long long
class Solution {
public:
    vector<long long> maximumSegmentSum(vector<int>& nums, vector<int>& qx) {
        int n = nums.size();
        vector<ll> ans(n,0);
        ll par[n+4];
        for(int i=0;i<=n+1;i++) par[i] = LLONG_MAX;
        
        auto find = [&](auto &&find,int x)->ll{
            if(par[x] < 0) return x;
            return par[x] = find(find,par[x]);
        };
        
        auto uni = [&](int x,int y){
            x = find(find,x);
            y = find(find,y);
            par[x]+=par[y];
            par[y] = x; 
        };
        
        for(int i=n-1;i>0;i--){
            int idx = qx[i];
            par[idx] = -nums[idx];
            if(idx-1>=0 && par[idx-1]!=LLONG_MAX) uni(idx,idx-1);
            
            if(idx+1<n && par[idx+1]!=LLONG_MAX) uni(idx,idx+1);
            ans[i-1] = max(ans[i],-par[find(find,idx)]);
        }
        
        return ans;
        
    }
};