class Solution {
public:
    long long countSubstrings(string s, char x) {
        long long ans = count(s.begin(),s.end(),x);
        ans*=(ans+1);
        ans/=2;
        return ans;
    }
};