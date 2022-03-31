class Solution {
public:
    int splitArray(vector<int>& nums, int m) { 
        int n=nums.size();
        int l=0;
        int r=0;
        int ans=-1;
        
        for(int &i:nums) r+=i,l=max(l,i);
    
        
        function<bool(int)> ok = [&](int x){
            int c=1;
            int ss=0;
            for(int i=0;i<n;i++){
                ss+=nums[i];
                if(ss>x){
                    c++;
                    ss=nums[i];
                }
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