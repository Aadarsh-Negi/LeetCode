int cnt[10004];
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, const int k) {
        memset(cnt,0,sizeof(cnt));
        cnt[0]++;
        int ans=0;
        int s=0;
        for(int i:nums){
            s+=i;
            while(s<0) s+=k;
            s%=k;
            ans+=cnt[s];
            cnt[s]++;
        }
        return ans;
    }
};