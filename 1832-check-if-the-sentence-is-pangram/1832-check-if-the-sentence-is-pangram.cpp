class Solution {
public:
    bool checkIfPangram(string c) {
        int cnt[26]={0};
        for(char &s:c) cnt[s-'a']++;
        bool ok = 1;
        for(int i=0;i<26;i++) ok&=cnt[i]>=1;
        return ok;
    }
};