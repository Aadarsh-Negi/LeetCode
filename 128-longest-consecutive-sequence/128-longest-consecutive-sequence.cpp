class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_map<int,int> cnt;
        
        int ans=0; 
        for(int &i:nums) cnt[i]++;
        for(int &i:nums){
            if(cnt[i-1]);
            else{
                int fs=i+1;
                int c=1;
                while(cnt[fs]) fs++,c++;
                ans=max(ans,c);
            }
        }
        return ans;
        
    }
};