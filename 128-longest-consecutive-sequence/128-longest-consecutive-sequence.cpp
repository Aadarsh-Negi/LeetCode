class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_set<int> cnt;
        
        int ans=0; 
        for(int &i:nums) cnt.insert(i);
        for(int &i:nums){
            if(cnt.count(i-1));
            else{
                int fs=i+1;
                int c=1;
                while(cnt.count(fs)) fs++,c++;
                ans=max(ans,c);
            }
        }
        return ans;
        
    }
};