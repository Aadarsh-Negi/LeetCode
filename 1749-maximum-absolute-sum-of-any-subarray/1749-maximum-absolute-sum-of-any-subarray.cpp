class Solution {
public:
    
    int solve(vector<int> &nums,int x){
        int m=0;
        int s=0;
        for(int &i:nums){
            if(x){
                s = min(i,s+i);
                m = min(m,s);
            }else{
                s = max(i,s+i);
                m = max(m,s);
            }
        }
        return abs(m);
    }
    
    int maxAbsoluteSum(vector<int>& nums) {
       return max(solve(nums,1),solve(nums,0));
        
    }
};