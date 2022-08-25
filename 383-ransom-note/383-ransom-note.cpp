class Solution {
public:
    bool canConstruct(string r, string s) {
        vector<int> cnt(27,0);
        for(char &c:s) cnt[c-'a']++;
        for(char &c:r) {cnt[c-'a']--; if(cnt[c-'a']<0) return 0;}
        return 1;
    }
};