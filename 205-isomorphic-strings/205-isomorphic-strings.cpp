class Solution {
public:
    bool ck(string s,string t){
        int cnt[200];
        memset(cnt,-1,sizeof(cnt));
   
    for(int i=0;i<s.size();i++){
        if(cnt[s[i]]!=-1)
            if(cnt[s[i]]!=t[i]) return 0;
        cnt[s[i]]=t[i];
    }
    return 1;
}
    bool isIsomorphic(string s, string t) {
      
        return ck(s,t) && ck(t,s);
    }
};