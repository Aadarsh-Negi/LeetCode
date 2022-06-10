const int N = 2e4 + 10;
class Solution {
public:
    vector<int> dp;
    unordered_map<int,int> cnt;
    
    int solve(int i,vector<int> &ar){
        if(i>=ar.size()-1) return 0;
        if(dp[i]!=-1) return dp[i];
        
        int temp = 0;
        if(ar[i+1]-1==ar[i])
            temp = ar[i]*cnt[ar[i]] + solve(i+2,ar);
        else temp = ar[i]*cnt[ar[i]] + solve(i+1,ar);
        return dp[i] = temp = max(temp,solve(i+1,ar));
    }
    
    int deleteAndEarn(vector<int>& nums) {
        dp.resize(N,-1);
        
        for(int &i:nums) cnt[i]++;
        
        sort(nums.begin(),nums.end());
        nums.erase(unique(nums.begin(),nums.end()),nums.end());
        
        nums.push_back(1e5);
        
        // for(int i:nums) cout<<i<<" ";
        
        return solve(0,nums);
    }
};