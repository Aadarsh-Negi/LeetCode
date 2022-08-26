class Solution {
public:
    
    void solve(vector<int>&nums, vector<vector<int>>&ans, vector<int>& output , vector<bool> &vis){
        if(output.size()==nums.size()){
            ans.push_back(output);
            return ;
        }
        // if(vis[idx] == true) return;
        
        for(int i=0;i<nums.size();i++){
            if(vis[i]) continue;
            //if(i == idx-1) continue;
            vis[i] = true;
            output.push_back(nums[i]);
            solve(nums, ans, output,vis);
            vis[i] = false;
            output.pop_back();
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        vector<bool> vis(nums.size(), false);
        
    
        solve(nums, ans, output,vis);
        return ans;
    }
};