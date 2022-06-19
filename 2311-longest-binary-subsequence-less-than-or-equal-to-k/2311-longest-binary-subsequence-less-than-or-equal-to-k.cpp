class Solution {
public:
    int longestSubsequence(string s, int k) {
        int ans=0;
        for(char &c:s) ans+=(c=='0');
        
        reverse(s.begin(),s.end());
        int cur=0;
        for(int i=0;i<min((int)s.size(),31);i++){
            if(s[i]=='0') continue;
            if((cur|(1<<i)) > k) break;
            ans++;
            cur|=(1<<i);
        }
        return ans;
    }
};