class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int>  cnt;
        int  ans=0;
        
        for(int i:nums){
            if(cnt[k-i]){
                ans++;
                cnt[k-i]--;
            }else cnt[i]++;
        }
        
        return ans;
    }
};