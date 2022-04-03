class Solution {
public:
    int maximumCandies(vector<int>& cand, long long k) {
        
        long long ans=0;
        long long l=1;
        long long r=1e9;
        
        auto ok = [&](long long x){
            long long cnt=0;
            for(int i:cand){
                cnt+=(i/x);
            }
            return cnt>=k;
        };
        
        while(l<=r){
            long long mid = l+ (r-l)/2;
            
            if(ok(mid)){
                ans=mid;
                l=mid+1;
            }else r=mid-1;
            
        }
        return ans;
        
        
    }
};