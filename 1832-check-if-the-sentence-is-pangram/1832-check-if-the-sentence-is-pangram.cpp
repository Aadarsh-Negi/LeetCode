class Solution {
public:
    bool checkIfPangram(string &s,char c='a') {
        return c<='z' ? find(s.begin(),s.end(),c) == s.end() ? 0 : checkIfPangram(s,c+1) : 1;
    }
};