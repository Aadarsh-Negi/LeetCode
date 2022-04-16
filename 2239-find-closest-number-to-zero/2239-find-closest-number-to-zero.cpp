class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        int ans;
        int val=INT_MAX;
        for(int i:nums){
            if(val>=abs(i)) ans=i,val=abs(i);
        }
        return ans;
        
    }
};