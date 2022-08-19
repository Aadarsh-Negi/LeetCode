class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        map<string,int> hash;
        vector<int> ans;
        int sz = words.size();
        int lx = words[0].size();
        for(string &c:words)
            hash[c]++;
        int n = s.size();
        for(int i=0;i<=n-lx*sz;i++){
            string sx;
            bool ok=1;
            int cc=0;
            map<string,int> cur;
            for(int k=0;k < sz*lx;k++){
                if(i+k<n){
                    sx+=s[i+k];
                }
                if(sx.size()==lx){
                    cur[sx]++;
                    if(cur[sx] > hash[sx]){
                        ok=0;
                        break;
                    }
                    cc++;
                    sx.clear();
                }
            }
            if(ok && cc==words.size()){
                ans.push_back(i);
            }
    
        }
        return ans;
        
        
    }
};