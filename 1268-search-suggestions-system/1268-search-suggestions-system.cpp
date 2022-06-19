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
        string ax;
        Trie *cur = this;
        for(const char &c:s){
            if(cur->ar[c-'a']==NULL) return ;
            ax+=c;
            cur = cur->ar[c-'a'];
        }
        dfs(cur,ax,temp);
    }
//         vector<string> temp;
//         // set<string> qq;
        
//         Trie *cur = this;
        
//         string ax;
        
//         for(const char &c:s){
//             if(cur->ar[c-'a']==NULL) return {};
//             ax+=c;
//             cur = cur->ar[c-'a'];
//             if(cur->end) temp.push_back(ax);
//             if(temp.size()==3) return temp;
// //             if(qq.size()>3){
// //                 auto it = qq.end(); it--;
                
// //                 qq.erase(it);
// //             }
//         }
//         int fl=0;
        void dfs(Trie *rx,string &ax,vector<string> &temp){
            if(temp.size()==3) return;
            if(rx->end) {temp.push_back(ax);}
            for(int i=0;i<27;i++){
                if(rx->ar[i]){
                    ax+=('a' + i);
                    dfs(rx->ar[i],ax,temp);
                    ax.pop_back();
                }
            }
        }
    
    
};
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& pp, string ss) {
        Trie *root = new Trie();
        for(string &s:pp) root->insert(s);
        
        string cur;
        vector<vector<string>> ans(ss.size());
        int i=0;
        for(char &c:ss){
            cur+=c;
            root->srch(cur,ans[i]);
            i++;
        }
        return ans;
    }
};