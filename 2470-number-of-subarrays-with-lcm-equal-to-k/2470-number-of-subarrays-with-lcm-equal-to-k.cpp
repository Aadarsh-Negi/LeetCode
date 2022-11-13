class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            long long l = nums[i];
            for(int j=i;j<nums.size();j++){
                l = lcm(l,(long long)nums[j]);
                if(l>k) break;
                if(l == k) ans++;
            }
        }
        return ans;
    }
};