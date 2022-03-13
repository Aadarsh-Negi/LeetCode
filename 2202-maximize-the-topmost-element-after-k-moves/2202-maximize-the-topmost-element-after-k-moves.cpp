class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        if(nums.size()==1 && (k&1)) return -1;
        if(k==1)  return nums[1];
        
        if(k==0) return nums[0];
        if(k>nums.size()) return *max_element(nums.begin(),nums.end());
        
        int mx = *max_element(nums.begin(),nums.begin()+k-1);
        
        mx = max(mx , k<nums.size()?nums[k]:-1);
        
        return mx;
    }
};