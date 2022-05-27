class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_set<int> cnt;
        
        int ans=0; 
        for(int &i:nums) cnt.insert(i);
        for(int &i:nums){
            if(cnt.find(i-1)!=cnt.end());
            else{
                int fs=i+1;
                int c=1;
                while(cnt.find(fs)!=cnt.end()) fs++,c++;
                ans=max(ans,c);
            }
        }
        return ans;
        
    }
};