class Solution {
public:
    int lengthOfLongestSubstring(string &s) {
     
        int cnt[505];
        memset(cnt,0,sizeof(cnt));
        
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