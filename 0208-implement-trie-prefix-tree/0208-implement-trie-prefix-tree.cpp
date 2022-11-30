class Trie {
public:
    int end;
    Trie *ar[26];
    Trie() {
        end=0;
        memset(ar,0,sizeof(ar));
    }
    
    void insert(string word) {
        Trie *cur = this;
        for(char c:word){
            if(!cur->ar[c-'a']) cur->ar[c-'a'] = new Trie;
            cur = cur->ar[c-'a'];
        }
        cur->end++;
    }
    
    bool search(string word) {
        Trie * cur=this;
        for(char &c:word){
            if(cur->ar[c-'a'])
                cur = cur->ar[c-'a'];
            else return 0;
        }
        return cur->end;
    }
       bool startsWith(string word) {
      Trie * cur =this;
        int cnt=1;
        for(char c:word){
            if(cur->ar[c-'a'])
                cur = cur->ar[c-'a'];
            else return 0;
            if(cnt==word.size()) return 1;
            cnt++;
        }
        return 0;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */