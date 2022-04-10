class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> stc;
        
        for(string &s:ops){
            if(s=="D") stc.push(stc.top()*2);
            else if(s=="C") stc.pop();
            else if(s=="+") {
                int  x = stc.top(); stc.pop();
                int y = stc.top();
                stc.push(x);
                stc.push(x + y);
            }else stc.push(stoi(s));
        }
        int ans=0;
        while(stc.size()) ans+=stc.top(),stc.pop();
        return ans;
        
    }
};