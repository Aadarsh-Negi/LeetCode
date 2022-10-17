bool cnt[26];
class Solution {
public:
    bool checkIfPangram(string &c) {
        memset(cnt,false,sizeof(cnt));
        int ok = 0;
        for(char &s:c){
            if(!cnt[s-'a']) ok++;
            cnt[s-'a'] = true;
        }
        return ok>=26;
        
    }
};