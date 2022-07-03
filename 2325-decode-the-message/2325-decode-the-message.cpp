class Solution {
public:
    string decodeMessage(string key, string message) {
        vector<int> cx(26,-1);
        char st = 'a';
        for(char &c:key){
            if(c==' ');
            else if(cx[c-'a']==-1)
                cx[c-'a'] = st++;
        }
        for(char &c:message){
            if(c!=' ')
                c = cx[c-'a'];
        }
        return message;
    }
};