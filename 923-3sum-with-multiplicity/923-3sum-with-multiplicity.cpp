class Solution {
public:
    int threeSumMulti(vector<int>& arr, int tar) {
        long long ans=0;
        const int mod = 1e9 + 7;
        int cnt[305]={0};
        cnt[arr[0]]++;
        for(int i=1;i<arr.size();i++){
            int tt = tar - arr[i];
            for(int j=i+1;j<arr.size();j++){
               if(tt-arr[j]<0) continue;
                ans+=cnt[tt-arr[j]];
                ans%=mod;
            }
            cnt[arr[i]]++;
            
        }
        return ans;
        
    }
};