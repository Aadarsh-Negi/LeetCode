class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> ar;
        for(int i=nums.size()-1;i>=0;i--){
            while(ar.size() && ar.top().second > i+k) ar.pop();
            int s = nums[i] + (ar.size() ? ar.top().first : 0);
            ar.push({s,i});
        } 
        while(ar.top().second!=0) ar.pop();
        
        return ar.top().first;
        
    }
};