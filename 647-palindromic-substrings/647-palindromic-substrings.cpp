class Solution {
public:
    int countSubstrings(string s) {
        int ans=0;
        
        auto cnt = [&](int l,int r){
            int c=0;
            while(l>=0 && r<s.size() && s[l]==s[r]){
                c++;
                l--;
                r++;
            }
            return c;
        };
        
        for(int i=0;i<s.size();i++){
            ans+=cnt(i,i)+cnt(i,i+1);
        }
        return ans;
    }
};