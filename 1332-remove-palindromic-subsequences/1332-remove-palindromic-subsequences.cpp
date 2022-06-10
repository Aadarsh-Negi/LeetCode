class Solution {
public:
    int removePalindromeSub(string &s) {
        return s.size()>1?(s.front()==s.back()?s.erase(s.begin()),s.pop_back(),removePalindromeSub(s):2):1;
        // while(s.size()>1 && s.front()==s.back()) s.erase(s.begin()),s.pop_back();
        // return s.size()>1?2:1;
    }
};