class Solution {
public:

    int maxSubarraySumCircular(vector<int>& nums) {
        int mx = nums[0];
        int mn = nums[0];
        int ttl = 0;
        int c1=0;
        int c2=0;
        for(int &i:nums){
            ttl+=i;
            c1+=i;
            c2+=i;
            mx = max(c1,mx);
            mn = min(c2,mn);
            c1 = max(c1,i);
            c2 = min(c2,i);
            if(c1 < 0) c1 = 0;
            if(c2 > 0) c2 = 0;
        }
        if(ttl == mn) ttl = INT_MIN/2;
        return max(mx,ttl - mn);
    }
};