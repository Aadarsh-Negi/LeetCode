class Solution {
public:
    int lengthOfLongestSubstring(string &s) {
     
        unordered_map<char,int> cnt;
        
        int i=0;
        int ls=0;
        int ans=0;
        while(i<s.size()){
            if(cnt[s[i]]==0){
                cnt[s[i++]]++;
            }else cnt[s[ls++]]--;
            ans = max(ans,i-ls);
        }
        return ans;
        
    }
};