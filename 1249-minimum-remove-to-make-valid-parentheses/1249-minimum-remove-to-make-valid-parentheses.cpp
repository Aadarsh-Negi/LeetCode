class Solution {
public:
    string minRemoveToMakeValid(string s) {
       stack<int> ar;
        
        for(int i=0;i<s.size();i++){
            char c = s[i];
            if(c=='(') ar.push(i);
            else if(c==')') if(ar.size() && s[ar.top()]=='(') ar.pop(); else ar.push(i);
        }
        while(ar.size()) s.erase(s.begin()+ar.top()),ar.pop();
        
        return s;
        
        
        
    }
};