class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
       int mx=0;
       int mn=0;
       int s=0;
        for(int i:nums){
            s+=i;
            mx = max(mx,s);
            mn = min(mn,s);
        }
        return mx-mn;
        
    }
};