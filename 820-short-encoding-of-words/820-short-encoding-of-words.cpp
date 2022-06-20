class Trie{
public:
    Trie *ar[27];
    int len;
    Trie(){
        for(int i=0;i<27;i++) ar[i] = NULL;
        len=0;
    }
    void insert(const string &s){
        Trie *cur=this;
        for(const char &c:s){
            if(cur->ar[c-'a']==NULL) cur->ar[c-'a'] = new Trie();
            cur = cur->ar[c-'a'];
        }
        cur->len=s.size();
    }
    bool isLeaf(Trie *rx){
        bool ok=1;
        for(int i=0;i<27;i++){
            ok&=(rx->ar[i]==NULL);
        }
        return ok;
    }
    int dfs(Trie *rx){
        if(isLeaf(rx)) return rx->len+1;
        int temp=0;        
        for(int i=0;i<27;i++)
            if(rx->ar[i]) temp+=dfs(rx->ar[i]);
        
        return temp;   
    }
};
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        Trie *root = new Trie();
        for(string &s:words){
            reverse(s.begin(),s.end());
            root->insert(s);
        }
        
        return root->dfs(root);
    }
};