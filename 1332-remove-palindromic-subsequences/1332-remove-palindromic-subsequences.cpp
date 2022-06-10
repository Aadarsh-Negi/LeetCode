class Solution {
public:
    int removePalindromeSub(string &s) {
        while(s.size()>1 && s.front()==s.back()) s.erase(s.begin()),s.pop_back();
        return s.size()>1?2:1;
    }
};