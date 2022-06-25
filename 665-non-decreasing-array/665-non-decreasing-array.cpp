class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        nums.push_back(1e6);
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i] > nums[i+1]){
                int prev = nums[i];
                nums[i]=nums[i+1];
                if(is_sorted(nums.begin(),nums.end())) return 1;
                
                nums[i]=prev;
                if(i+2<nums.size()){
                    nums[i+1] = nums[i+2];
                    if(is_sorted(nums.begin(),nums.end())) return 1;
                }
                
                return 0;
                
            }
        }
        return 1;
    }
};