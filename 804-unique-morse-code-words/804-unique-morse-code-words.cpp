class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string code[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        
        unordered_set<string> ans;
        
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