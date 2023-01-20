class Solution {
public:
   
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        
        vector<vector<int>> ans;
        set<vector<int>> seen;
        for(int i=1;i<(1<<nums.size());i++){
            vector<int> temp;
            
            for(int j=0;j<nums.size();j++)
                if((1<<j)&i){
                    if(temp.size()==0 || temp.back() <= nums[j])
                        temp.push_back(nums[j]);          
                    else break;
                }
                    
            
            if(temp.size()>1 && seen.find(temp)==seen.end()) {
                ans.push_back(temp);
                seen.insert(temp);
            }
        }
        
        return ans;
    }
};