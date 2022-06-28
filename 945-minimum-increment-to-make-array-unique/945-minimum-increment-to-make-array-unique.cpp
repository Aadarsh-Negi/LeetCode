class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=0;
        int prev=-1;
        for(int &i:nums){
            if(prev==-1) prev=i;
            else{
                if(prev>=i){
                    ans+=(prev + 1) - i;
                    i = prev + 1;
                }
            }
            prev=i;
        }
        return ans;
        
    }
};