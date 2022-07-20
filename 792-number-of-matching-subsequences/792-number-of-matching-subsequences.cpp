class Trie{
public:
  int end;
  vector<Trie*> ar;
    Trie(){
        end=0;
        ar.resize(27,NULL);
    }
    void insert(string &s){
        Trie *cur = this;
        for(char &c:s){
            if(cur->ar[c-'a']==NULL) cur->ar[c-'a'] = new Trie();
            cur=cur->ar[c-'a'];
        }
        cur->end++;
    }
    int dfs(vector<vector<int>> &pos,int idx,Trie *rx){
        // if(!rx) return 0;
        int temp=0;
        for(int i=0;i<27;i++){
            if(rx->ar[i]==NULL) continue;
            int cx = upper_bound(pos[i].begin(),pos[i].end(),idx) - pos[i].begin();
            if(cx==pos[i].size()) continue;
                temp+=dfs(pos,pos[i][cx],rx->ar[i]);
            // }
        }
        return temp+rx->end;
    }
    
        
    
    
};
class Solution {
public:
    int numMatchingSubseq(string &s, vector<string>& w) {
        
            Trie *t = new Trie();
            for(string &cx:w)
                t->insert(cx);
            vector<vector<int>> pos(27);
            for(int i=0;i<s.size();i++) pos[s[i]-'a'].push_back(i); 
         
        return t->dfs(pos,-1,t);
    }
};