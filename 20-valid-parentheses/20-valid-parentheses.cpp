class Solution {
public:
    bool isValid(string s) {
        stack<char> ck;
        
        
        for(char &c:s){
          if(c=='(' || c=='{' || c=='[') ck.push(c);
          else{
             if(ck.size()==0) return 0;
             if(ck.top() == '(' and c==')') ck.pop();
             else if(ck.top() == '[' and c==']') ck.pop();
             else if(ck.top() == '{' and c=='}') ck.pop();
             else return 0;
           }  
            
        }
        if(ck.size()) return 0;
        return 1;
    }
};