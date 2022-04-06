class Solution {
public:
    int threeSumMulti(vector<int>& arr, int tar) {
        long long ans=0;
        const int mod = 1e9 + 7;
        for(int i=1;i<arr.size();i++){
            int tt = tar - arr[i];
            int cnt[305]={0};
            for(int j=i-1;j>=0;j--) cnt[arr[j]]++;
            
            for(int j=i+1;j<arr.size();j++){
               if(tt-arr[j]<0) continue;
                ans+=cnt[tt-arr[j]];
                ans%=mod;
            }
            
        }
        return ans;
        
    }
};