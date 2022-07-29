class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& w, string p) {
        vector<string> ans;
        
        for(string &s:w){
            if(s.size()==p.size()){
                bool ok=1;
                vector<int> cnt(27,-1);
                vector<int> opp(27,-1);
                for(int i=0;i<s.size();i++){
                    if(cnt[p[i] - 'a']==-1 && opp[s[i]-'a']==-1){
                        cnt[p[i] - 'a'] = s[i];
                        opp[s[i]-'a'] = p[i];
                    }else{
                        if(cnt[p[i] - 'a'] == s[i] && opp[s[i]-'a'] == p[i]);
                        else {ok=0; break;}
                    }
                }
                if(ok) ans.push_back(s);
            }
            
        }
        return ans;
        
    }
};