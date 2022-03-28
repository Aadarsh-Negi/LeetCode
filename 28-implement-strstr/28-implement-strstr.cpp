class Solution {
public:
    int strStr(string text, string to_find) {
     
        if(text==to_find) return 0;
        
        
        return text.find(to_find);
        
       
        
    }
};