class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> ar;
        
        for(int i:nums){
            int it = lower_bound(ar.begin(),ar.end(),i)-ar.begin();
            if(it==ar.size()) ar.push_back(i);
            else ar[it] = i;
        }
        return ar.size();
    }
};