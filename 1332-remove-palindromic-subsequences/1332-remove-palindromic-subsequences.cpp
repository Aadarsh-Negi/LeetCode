class Solution {
public:
    int removePalindromeSub(string s,int i=0) {
        return s.size()>1?(s.front()==s.back()?removePalindromeSub(s.substr(i+1,s.size()-2)):2):1;
    }
};