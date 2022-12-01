class Solution {
public:
    bool halvesAreAlike(string s) {
        
        string fc = "aeiou";
        string sc = "AEIOU";
        int c=0;
        for(int i=0;i<s.size()/2;i++) c+=(fc.find(s[i])!=string::npos || sc.find(s[i])!=string::npos);
        
        for(int i=s.size()/2;i<s.size();i++) c-=(fc.find(s[i])!=string::npos || sc.find(s[i])!=string::npos);
        
        
        
        return c==0;
    }
};