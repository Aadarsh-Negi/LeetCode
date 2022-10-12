class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(i+2<nums.size()){
                int a = nums[i];
                int b = nums[i+1];
                int c = nums[i+2];
                
                if(a+b > c){
                    ans=max(ans,a+b+c);
                }
                
            }
            
        }
        return ans;
        
    }
};