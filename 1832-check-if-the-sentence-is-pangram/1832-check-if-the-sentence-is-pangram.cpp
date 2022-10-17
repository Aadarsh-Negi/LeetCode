class Solution {
public:
    bool checkIfPangram(string c) {
        int cnt[26]={0};
        for(char &s:c) cnt[s-'a']++;
        for(int i=0;i<26;i++) if(!cnt[i]) return false;
        return true;
    }
};