class Trie{
public:
    Trie *ar[27];
    int end;
    
    Trie(){
        end=0;
        for(int i=0;i<27;i++) ar[i] = NULL;
    }
    void insert(const string &s){
        Trie *cur = this;
        int i=0;
        for(const char &c:s){
            if(cur->ar[c-'a']==NULL) cur->ar[c-'a'] = new Trie();
            cur = cur->ar[c-'a'];
            if(i==s.size()-1) cur->end=1;
            i++;
        }
    }
    void srch(const string &s,vector<string> &temp){
        Trie *cur = this;
        string ax = s;
        for(const char &c:s){
            if(cur->ar[c-'a']==NULL) return;
            cur = cur->ar[c-'a'];
        }
        function<void(Trie *)> rem = [&](Trie *rx){
            if(temp.size()==3) return;
            if(rx->end) temp.push_back(ax);
            for(int i=0;i<27;i++){
                if(rx->ar[i]){
                    ax+=('a' + i);
                    rem(rx->ar[i]);
                    ax.pop_back();
                }
            }
        };
        rem(cur);
    }
};
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& pp, string ss) {
        Trie *root = new Trie();
        for(string &s:pp) root->insert(s);
        
        string cur;
        vector<vector<string>> ans(ss.size());
        for(char &c:ss){
            cur+=c;
            root->srch(cur,ans[cur.size()-1]);
        }
        return ans;
    }
};