class Solution {
public:
    int triangularSum(vector<int>& nums) {
        
        while(nums.size()>1){
            vector<int> temp;
            
            for(int i=0;i<nums.size()-1;i++){
                int v = nums[i]+nums[i+1];
                temp.push_back(v%10);
            }
            nums=temp;
            
        }
        return nums[0];
    }
};