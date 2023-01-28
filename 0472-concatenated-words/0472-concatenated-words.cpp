class Trie{
  public:
    int end;
    Trie *ar[27];
    Trie(){
        memset(ar,0,sizeof(ar));
        end=0;
    }
    void insert(string &a){
        Trie *root = this;
        for(char &c:a){
            if(!root->ar[c-'a']) root->ar[c-'a'] = new Trie();
            root = root->ar[c-'a'];
        }
        root->end++;
    }
};
int dp[35][35];
class Solution {
public:
    Trie *root;
    bool ok(string &s,int ix,int cnt,Trie *cur){
        if(ix>=s.size()) return cnt>1;
        if(dp[ix][cnt]!=-1) return dp[ix][cnt];
        for(int i=ix;i<s.size();i++){
            char c = s[i];
            if(cur->ar[c-'a']){
                cur = cur->ar[c-'a'];
                if(cur->end){
                    if(ok(s,i+1,cnt+1,root)) return dp[ix][cnt] = true;
                }
            }else return dp[ix][cnt] = false;
        }
        return dp[ix][cnt] = false;
    }
    
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        root = new Trie();
        
        for(string &s:words){
          root->insert(s);
        } 
        vector<string> ans;
        for(string &s:words){
            memset(dp,-1,sizeof(dp));
            if(ok(s,0,0,root)) 
                ans.push_back(s);
            // break;
        }
        
        return ans;
        
    }
};