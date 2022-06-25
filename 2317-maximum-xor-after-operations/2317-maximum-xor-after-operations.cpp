class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        int ans=0;
        for(const int &i:nums) ans|=i;
        return ans;
    }
};