class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> temp = nums;
        
        sort(temp.begin(),temp.end());
        int j=-1;
        int k=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=temp[i]){
                if(j==-1) j=i;
                k=i;
            }
        }
        if(k==j) return 0;
        return k-j+1;
        
    }
};