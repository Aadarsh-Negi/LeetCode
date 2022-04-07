class Solution {
public:
    bool ck(string s,string t){
        int cnt[405];
        memset(cnt,-1,sizeof(cnt));
   
    for(int i=0;i<s.size();i++){
        if(cnt[s[i]]!=-1){
            if(cnt[s[i]]!=t[i]) return false;
        }
       else  cnt[s[i]]=t[i];
    }
    return true;
}
    bool isIsomorphic(string s, string t) {
      
        return ck(s,t) && ck(t,s);
    }
};