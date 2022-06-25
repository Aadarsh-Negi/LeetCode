class Solution {
public:
    int maximumXOR(vector<int>& nums,int i=0) {
        return i<nums.size()?nums[i]|maximumXOR(nums,i+1):0;
    }
};