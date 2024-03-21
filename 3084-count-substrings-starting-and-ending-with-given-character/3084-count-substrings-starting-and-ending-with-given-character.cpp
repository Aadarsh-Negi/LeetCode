class Solution {
public:
    long long countSubstrings(string s, char x) {
        long long ans = 0;
        map<int,int> cnt;
        
        for(char &c:s){
            cnt[c]++;
            if(c == x) ans+=cnt[c];
        }
        return ans;
    }
};