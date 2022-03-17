class Solution {
public:
    int scoreOfParentheses(string s) {
        int rem=0;
        char prev='?';
        int ans=0;
        for(char &c:s){
            if(c=='(') rem++;
            else{
                rem--;
                if(prev=='(') ans+=(1<<rem);
                
            }
            prev=c;
        }
        return ans;
        
        
    }
};