class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> aa(nums.begin(),nums.end());
        return nums.size() != aa.size();
    }
};