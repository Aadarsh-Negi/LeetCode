class Solution {
public:
    int longestStrChain(vector<string>& words) {
        
        sort(words.begin(),words.end(),[&](const string &a,const string &b){
           return a.size() < b.size();
        });
        
        map<string,int> prev;
        int ans=0;
        for(const string &s:words){
            int len=0;
            for(int i=0;i<s.size();i++){
                string temp = s;
                temp.erase(temp.begin()+i);
                len=max(len,prev[temp]+1);
            }
            prev[s] = len;
            ans=max(len,ans);
        }
        return ans;
        
        
    }
};