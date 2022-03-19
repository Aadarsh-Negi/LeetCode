class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int,int> cnt;
        for(int i:nums) cnt[i]++;
        for(auto i:cnt) if(i.second&1) return 0;
        
        return 1;
    }
};