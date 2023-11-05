class Solution {
public:
    int longestPalindrome(string s) {
        int ans = 0;
        unordered_map<int,int> cnt;
        
        for(char &c:s) cnt[c]++;
        
        bool odd = 0;
        for(auto it:cnt){
            ans+=(it.second/2);
            odd|=(it.second&1);
        }
        return ans*2 + odd;
        
    }
};