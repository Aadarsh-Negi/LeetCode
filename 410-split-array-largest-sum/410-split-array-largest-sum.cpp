class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int sum=0; int n=nums.size();
        for(int i:nums) sum+=i;
        int l=0;
        int r=sum;
        int ans=sum;
        
        function<bool(int)> ok = [&](int x){
            int c=1;
            int ss=0;
            for(int i=0;i<n;i++){
                if(nums[i]>x) return false;
                if(ss+nums[i]>x){
                    c++;
                    ss=nums[i];
                    continue;
                }
                ss+=nums[i];
            }
            return c<=m;
        };
        
        while(l<=r){
            int mid = l + (r-l)/2;
            if(ok(mid)) ans=mid,r=mid-1;
            else l=mid+1;
        }
        return ans;
    }
};