class Solution {
public:
    int minMutation(string s, string t, vector<string>& bank) {
        if(find(bank.begin(),bank.end(),t)==bank.end())return-1;
        set<string>cc(bank.begin(),bank.end()); 
        cc.erase(s);
        queue<string>qq;
        qq.push(s);
        int ans=0;
        
        char ch[]={'A','C','G','T'};
        while(qq.size()){
            int sz=qq.size();
            while(sz--){
                string x=qq.front();qq.pop();
                if(x==t)return ans;
                for(char &c:x){
                    char p=c;
                    for(int i=0;i<4;i++){
                        c=ch[i];
                        auto it=cc.lower_bound(x);
                        if(it!=cc.end() && *it==x){
                            qq.push(x);
                            cc.erase(x);
                        }    
                    }
                    c=p;
                        
                }
                
            }
            ans++;
        }
        return -1;
    }
};