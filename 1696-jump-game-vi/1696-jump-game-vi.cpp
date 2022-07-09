class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        deque<pair<int,int>> ar;
        int n = nums.size();
        
        for(int i=0;i<n;i++){
            
            if(ar.size() && ar.front().second < i-k) ar.pop_front();
            
            int s = (ar.size() ? ar.front().first : 0) + nums[i];
            
            while(ar.size() && ar.back().first <= s) ar.pop_back();
            
            ar.push_back({s,i});
        } 
        return ar.back().first;
    }
};