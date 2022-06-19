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
    vector<string> srch(const string &s){
        vector<string> temp;
        priority_queue<string> qq;
        
        Trie *cur = this;
        
        string ax;
        
        for(const char &c:s){
            if(cur->ar[c-'a']==NULL) return {};
            ax+=c;
            cur = cur->ar[c-'a'];
            // if(cur->end) qq.push(ax);
            // if(qq.size()>3) qq.pop();
        }
        
        function<void(Trie *)> rem = [&](Trie *rx){
            if(rx->end) {qq.push(ax); if(qq.size()>3) qq.pop();}
            for(int i=0;i<27;i++){
                if(rx->ar[i]){
                    ax+=('a' + i);
                    rem(rx->ar[i]);
                    
                    ax.pop_back();
                }
            }
        };
        // for(int i=0;i<27;i++)
            rem(cur);
        
        while(qq.size()) temp.push_back(qq.top()),qq.pop();
        
        reverse(temp.begin(),temp.end());
        return temp;
    }
    
    
};
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& pp, string ss) {
        Trie *root = new Trie();
        for(string &s:pp) root->insert(s);
        
        string cur;
        vector<vector<string>> ans;
        for(char &c:ss){
            cur+=c;
            ans.push_back(root->srch(cur));
        }
        return ans;
    }
};