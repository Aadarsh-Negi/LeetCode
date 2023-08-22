class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> val(n+1);
        unordered_map<int,int> prev;
        for(int i=0;i<n;i++){
            if(prev[nums[i]]){
                int cc = i - prev[nums[i]];
                val[nums[i]].push_back(cc);   
            }
            prev[nums[i]] = i+1;
        }
        
        int ans = 1;
        
        for(vector<int> &a:val){
            for(int i=1;i<a.size();i++){
                a[i]+=a[i-1];
            }
            auto ok = [&](int cnt,int K){
                for(int i=cnt;i<a.size();i++){
                    if(a[i] - (i-cnt-1>=0 ? a[i-cnt-1]:0) <= K) return true;
                }
                return false;
                
            };
            
            
            int l = 1;
            int r = a.size();
            int temp = 0;
            while(l<=r){
                int mid  = l + (r-l)/2;
                if(ok(mid-1,k)){
                    temp = mid;
                    l = mid+1;
                }else r = mid-1;
            }
            ans=max(ans,1+temp);
        }
        
        
        return ans;
    }
};