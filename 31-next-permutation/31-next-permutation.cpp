class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i=nums.size()-1;
        while(i-1>=0 && nums[i]<=nums[i-1]) i--;
        
        if(i>0){
            int k=nums.size()-1;
            while(k>=0 && nums[k]<=nums[i-1]) k--;
            swap(nums[k],nums[i-1]);
        }
        int j=nums.size()-1;
        while(i<j) swap(nums[i++],nums[j--]);
        
    }
};