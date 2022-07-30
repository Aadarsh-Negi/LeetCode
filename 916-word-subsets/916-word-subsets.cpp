class Solution {
public:
    vector<string> wordSubsets(vector<string>& w1, vector<string>& w2) {
        vector<string> ans;
        
        vector<int> cnt(27,0);
        
        for(string &s:w2){
            vector<int> temp(27,0);
            for(char &c:s){
                temp[c-'a']++;
                cnt[c-'a'] = max(cnt[c-'a'],temp[c-'a']);
            }
        }
            
        
        
        for(string &s:w1){
            vector<int> temp(27,0);// = cnt;
            bool ok=1;
            for(char &c:s){
                temp[c-'a']++;
            } 
            
            for(int i=0;i<27;i++){
                if(cnt[i]){
                    if(temp[i]<cnt[i]) {ok=0; break;}
                }
            }
            
            if(ok) ans.push_back(s);
        }
            
            return ans;
            
    }
};