class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<string> stc;
        
        for(string &s:ops){
            if(s=="D"){
                int prev = stoi(stc.top()) * 2;
                stc.push(to_string(prev));
            }else if(s=="C") stc.pop();
            else if(s=="+") {
                string x  = stc.top(); stc.pop();
                string y = stc.top();
                stc.push(x);
                stc.push(to_string(stoi(x) + stoi(y)));
            }else stc.push(s);
        }
        int ans=0;
        while(stc.size()) ans+=stoi(stc.top()),stc.pop();
        return ans;
        
    }
};