class Solution {
public:
    vector<string> res;
    string s;
    vector<string> mp;
    void solve(int jj,string cur){
        if(jj>=s.size()){
            if(cur.size()) res.push_back(cur);
            return;
        }
        for(char &c:mp[s[jj]-'0']) solve(jj+1,cur+c);
    }
    
    vector<string> letterCombinations(string digits) {
        s=digits;
        mp.resize(12);
        mp['2' - '0'] = "abc";
        mp['3' - '0'] = "def";
        mp['4' - '0'] = "ghi";
        mp['5' - '0'] = "jkl";
        mp['6' - '0'] = "mno";
        mp['7' - '0'] = "pqrs";
        mp['8' - '0'] = "tuv";
        mp['9' - '0'] = "wxyz";
        solve(0,"");
        return res;
        
    }
};