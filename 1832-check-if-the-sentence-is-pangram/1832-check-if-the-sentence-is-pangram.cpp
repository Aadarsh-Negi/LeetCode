class Solution {
public:
    bool checkIfPangram(string c) {
        set<int> s(c.begin(),c.end());
        return s.size()>=26;
    }
};