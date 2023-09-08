class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) {
        long long ans = 0;
        vector<long long> suff(nums.size()+1);
        long long curr = 0;
        for(int i=nums.size()-1;i>=0;i--){
            curr|=nums[i];
            suff[i] = curr;
        }

        curr = 0;

        for(int i=0;i<nums.size();i++){
            long long temp = curr;
            temp |= (nums[i]*(1LL<<k));
            ans = max(ans,(temp)|(suff[i+1]));
            curr |= nums[i];
        }

        return ans;
    }
};