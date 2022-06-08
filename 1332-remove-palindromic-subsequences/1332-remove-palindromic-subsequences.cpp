class Solution {
public:
    int removePalindromeSub(string s) {
        string s2 = s;
        reverse(s2.begin(),s2.end());
        if(s2==s) return 1;
        return 2;
    }
};