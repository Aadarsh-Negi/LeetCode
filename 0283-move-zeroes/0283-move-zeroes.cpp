class Solution {
public:
    void moveZeroes(vector<int>& nums) {
       int lastElement = 0;
       int currentIndex = 0;
       while(currentIndex < nums.size()){
           if(nums[currentIndex] != 0){
               swap(nums[currentIndex],nums[lastElement++]);
           }
           currentIndex++;
       }
    }
};