class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<long> cc;
        for(string &s:tokens){
            if(s=="+"){
                long a = cc.back(); cc.pop_back();
                long b = cc.back(); cc.pop_back();
                cc.push_back(0LL+a+b);
                
            }else if(s=="-"){
               long a = cc.back(); cc.pop_back();
                long b = cc.back(); cc.pop_back();
                cc.push_back(0LL+b-a);
            }else if(s=="/"){
               long a = cc.back(); cc.pop_back();
                long b = cc.back(); cc.pop_back();
                cc.push_back(0LL+b/a);
            }else if(s=="*"){
                 long a = cc.back(); cc.pop_back();
                long b = cc.back(); cc.pop_back();
                cc.push_back(0LL+a*b);
            }else cc.push_back(stoll(s));
        }
        return cc.back();
    }
};