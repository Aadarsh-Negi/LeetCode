class Solution {
public:
   
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        
        vector<vector<int>> ans;
        
        for(int i=1;i<(1<<nums.size());i++){
            vector<int> temp;
            for(int j=0;j<nums.size();j++)
                if((1<<j)&i) temp.push_back(nums[j]);           
            if(temp.size()>1 && is_sorted(temp.begin(),temp.end())) ans.push_back(temp);
        }
        sort(ans.begin(),ans.end());
        ans.erase(unique(ans.begin(),ans.end()),ans.end());
        return ans;
    }
};