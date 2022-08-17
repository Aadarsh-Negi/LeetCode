class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> code = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        
        set<string> ans;
        
        for(string &s:words){
            string temp;
            for(char &c:s){
                temp+=(code[c-'a']);
            }
            ans.insert(temp);
        }
        return ans.size();
        
    }
};