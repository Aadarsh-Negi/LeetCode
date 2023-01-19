class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        map<int,int> cnt;
        cnt[0]++;
        int ans=0;
        int s=0;
        for(int i:nums){
            s+=i;
            while(s<0) s+=k;
            ans+=cnt[s%k];
            cnt[s%k]++;
        }
        return ans;
    }
};