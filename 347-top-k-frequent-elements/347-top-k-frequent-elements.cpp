class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        map<int,int> cnt;
        for(int &i:nums) cnt[i]++;
        
       sort( nums.begin(), nums.end() );
        nums.erase( unique( nums.begin(), nums.end() ), nums.end() );
        
        
        sort(nums.begin(),nums.end(),[&](const int &a,const int &b){
            return cnt[a]>cnt[b];
        });
        
        while(nums.size()>k) nums.pop_back();
        return nums;
        
        
    }
};