class Solution {
public:
    int removePalindromeSub(string s,int i=0) {
        return equal(s.begin(),s.begin() + s.size()/2,s.rbegin())?1:2;
    }
};