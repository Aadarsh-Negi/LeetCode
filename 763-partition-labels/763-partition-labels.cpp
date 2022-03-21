class Solution {
public:
    vector<int> partitionLabels(string s) {
        int prev=-1;
        vector<int> ans;
        vector<int> cnt(26,0);
        
        for(char &c:s) cnt[c-'a']++;
        vector<int> cur(26,0);
        
        for(int i=0;i<s.size();i++){
           char c= s[i];
            cur[c-'a']++;
            bool ok=1;
            for(int j=0;j<26;j++){
                if(!cur[j])continue;
                ok&=(cur[j]==cnt[j]);
            }
            if(ok){
                ans.push_back(i-prev);
                for(int &k:cur) k=0;
                prev=i;
            }
        }
        return ans;
        
        
    }
};