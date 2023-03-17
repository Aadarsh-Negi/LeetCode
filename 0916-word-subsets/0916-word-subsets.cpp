class Solution {
public:
    vector<string> wordSubsets(vector<string>& w1, vector<string>& w2) {
        vector<string> ans;
        
        int cnt[26] = {0};
        
        for(string &s:w2){
            int temp[26] = {0};
            for(char &c:s){
                temp[c-'a']++;
                cnt[c-'a'] = max(cnt[c-'a'],temp[c-'a']);
            }
        }
            
        
        
        for(string &s:w1){
            int temp[26] = {0};
            bool ok=0;
            for(char &c:s)
                temp[c-'a']++;
            for(int i=0;i<26;i++)
                    ok|=(temp[i]<cnt[i]) ;
            
            
            if(!ok) ans.push_back(s);
        }
            
            return ans;
            
    }
};