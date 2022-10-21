class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> ar;
        bool ok = 0;
        for(int i=0;i<nums.size();i++){
            if(ar[nums[i]])
                ok|=((i+1) - ar[nums[i]] <=k);
            ar[nums[i]] = i+1;
        }
        return ok;
    }
};