class Solution {
public:
    string breakPalindrome(string s) {
        if(s.size()==1) return "";
        int i=0;
        while(i<s.size() && (i==s.size()/2 || s[i]=='a' )) i++;
        
        if(i==s.size()) s.back()++;
        else s[i]='a';
        
        
        return s;
        
    }
};