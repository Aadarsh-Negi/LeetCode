class Solution {
public:
    string reverseWords(string s) {
        
        int prev=0;
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
                reverse(s.begin()+prev,s.begin()+i);
                prev = i+1;
            }
        }
        reverse(s.begin()+prev,s.end());
        
        return s;
    }
};