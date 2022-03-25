class Solution {
public:
    bool isValid(string s) {
     
        stack<int> st;
        
        
        for(char &c:s){
            if(c=='(' || c=='{' || c=='[') st.push(c);
            else{
                if(st.size()==0) return 0;
                
                if(st.top()=='(' && c==')') st.pop();
                else if(st.top()=='{' && c=='}') st.pop();
                else if(st.top()=='[' && c==']') st.pop();
                else return 0;
            }
        }
        
        
        if(st.size()==0) return 1;
        
        return 0;
        
    }
};