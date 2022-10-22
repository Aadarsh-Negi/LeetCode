class Solution {
public:
    string minWindow(string s, string t) {
        int r=-1;
        string ans;
        int mn=INT_MAX;
        int last=0;
        int n = s.size();
        
        map<char,int> cnt;
        map<char,int> cnt2;
        for(char &c:t) cnt2[c]++;
        
        auto ok = [&](){
          for(auto &[c,cx]:cnt2){
                if(cx > cnt[c]){
                    return 0;
                }
            }
            return 1;
        };
        int i=0;
        s+='.';
        while(i<=n){
            while(ok()){
                    int len = i-last;
                    if(len < mn){
                        mn = len;
                        r=last;
                    }       
                    cnt[s[last++]]--;
                }
                cnt[s[i++]]++;
            
        }
        if(mn == INT_MAX) return "";
        while(mn--){
            ans+=s[r++];
        }
        return ans;
        
        
    }
};