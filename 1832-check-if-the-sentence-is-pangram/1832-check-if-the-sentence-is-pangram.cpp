class Solution {
public:
    bool checkIfPangram(string &c) {
        int cnt[26]={0};
        int ok = 0;
        for(char &s:c){
            if(!cnt[s-'a']) ok++;
            cnt[s-'a']++;
        }
        return ok>=26;
        
    }
};