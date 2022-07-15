using ll  = long long;
class Solution {
public:
    long long minSumSquareDiff(vector<int>& a, vector<int>& b, int k1, int k2) {
           vector<long long> ar;
            for(int i=0;i<a.size();i++){
                ar.push_back(abs(a[i]-b[i]));
            }
            
        ll l=0;
        ll r = 1e15;
        ll xx = 0;
        ll cap=0;
        while(l<=r){
            ll mid = l + (r-l)/2;
            
            ll ops=0;
            
            for(auto i:ar){
                ops+=max(0LL,i-mid);
            }
            
            if(ops<=k1+k2){
                xx = k1+k2 - ops; 
                cap = mid;
                r = mid-1;
            }else l = mid+1;
        }
        long long ans=0;
        for(auto &i:ar){
            if(i >= cap) i=max(0LL,0LL + cap - (--xx>=0 ? 1:0));
            ans+=(i*i*1LL);
        }
        return ans;
    }
};