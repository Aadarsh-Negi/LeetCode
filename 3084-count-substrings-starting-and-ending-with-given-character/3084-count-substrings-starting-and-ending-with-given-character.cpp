class Solution {
public:
    long long countSubstrings(string s, char x) {
        long long ans = 0;
        for(char &c:s) ans += (c==x);
        ans*=(ans+1);
        ans/=2;
        return ans;
    }
};