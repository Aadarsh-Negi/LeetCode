class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        vector<long long> pref(nums.size()+3,0);
        vector<long long> suff(nums.size()+3,0);
        int n = nums.size();
        // pref[1] = nums[0];
        
        
        for(int i=1;i<=n;i++) pref[i]+=pref[i-1]+nums[i-1];
        
        reverse(nums.begin(),nums.end());
        // suff[1] = nums[0];
        for(int i=1;i<=n;i++) suff[i]+=suff[i-1]+nums[i-1];
        
        // for(int i:pref) cout<<i<<" ";cout<<"\n";
        // for(int i:suff) cout<<i<<" ";cout<<"\n";
        
        long long ans=LLONG_MAX;
        int ind=-1;
        
        for(int i=1;i<=n;i++){
            long long v1 = pref[i]/(i);
            long long v2=0;
            if(n-i == 0);// v2=0;
            else
                v2 = suff[n-i]/(n-i);
            // cout<<i<<" "<<(n-i-1)<<"<\n";
            // cout<<abs(v1-v2)<<"\n";
            if(ans > abs(v1-v2)){
                ans=abs(v1-v2);
                ind = i-1;
            }
        }
        // cout<<"\n";
        
        
        return ind;
    }
};