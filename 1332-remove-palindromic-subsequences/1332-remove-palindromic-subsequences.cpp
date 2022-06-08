class Solution {
public:
    int removePalindromeSub(string s) {
        int i=0;
        int j=s.size()-1;
        while(i<j && s[i]==s[j]) i++,j--;
        if(i<j) return 2;
        return 1;
    }
};