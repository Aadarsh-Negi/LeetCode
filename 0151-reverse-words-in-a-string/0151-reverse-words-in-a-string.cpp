class Solution {
public:
    string reverseWords(string s) {
        s = ' '+ s;
        
        int i=s.size()-1;
        while(i>=0 && s[i]==' ') i--;
        
        string ans;
        string temp;
        while(i>=0){
            if(s[i]==' '){
                reverse(temp.begin(),temp.end());
                ans+=temp;
                ans+=' ';
                temp.clear();
                while(i>=0 && s[i]==' ') i--;
            }else temp+=s[i--];
        }
        if(ans.size())
             ans.pop_back();
        return ans;
    }
};