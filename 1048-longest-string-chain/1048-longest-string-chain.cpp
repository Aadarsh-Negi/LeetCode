class Solution {
public:
    int longestStrChain(vector<string>& words) {
        unordered_map<string,int> avl;
        for(string &s:words){
            avl[s]=1;
        }
        
        sort(words.begin(),words.end(),[&](const string &a,const string &b){
           return a.size() > b.size();
        });
        unordered_map<string,int> done;
        
        int ans=0;
        for(string &s:words){
            if(done[s]) continue;
            // done[s]=1;
            queue<string> qq;
            qq.push(s);
            int cnt=0;
            while(qq.size()){
                int x = qq.size();
                
                while(x--){
                    
                    string cur = qq.front(); qq.pop();
                    if(done[cur]) continue;
                    done[cur]=1;
                    int sx = cur.size();
                    for(int i=0;i<sx;i++){
                        string temp = cur;
                        temp.erase(temp.begin()+i);
                        if(avl[temp]){
                            qq.push(temp);
                        }
                    }
                }
                cnt++;
            }
            ans = max(ans,cnt);
            
            
        }
        return ans;
        
        
    }
};