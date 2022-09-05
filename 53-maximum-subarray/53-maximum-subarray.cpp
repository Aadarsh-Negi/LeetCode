class Solution {
public:
    int maxSubArray(vector<int>& nums) {
      int curSum = 0;
      int maxSum = nums[0];
      for(int element:nums){
          curSum=max(curSum+element,element);
          maxSum = max(curSum,maxSum);
      }  
        return maxSum;
        
    }
};