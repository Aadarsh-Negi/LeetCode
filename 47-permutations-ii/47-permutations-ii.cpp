class Solution {
public:
    vector<vector<int>> ans;
    vector<int> vis;
    
    void solve(vector<int> &nums,vector<int> &temp){
        
        if(temp.size()>=nums.size()){
            ans.push_back(temp);   
            return;
        }
        
        for(int j=0;j<nums.size();j++){
            if(vis[j]) continue;
            vis[j]=1;
            temp.push_back(nums[j]);
            solve(nums,temp);
            temp.pop_back();        
            vis[j]=0;
        }
        
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vis.resize(nums.size()+1,0);
        vector<int> temp;
        solve(nums,temp);
        sort(ans.begin(),ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        
        return ans;
        
    }
};