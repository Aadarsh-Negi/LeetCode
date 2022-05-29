class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<vector<int>> cnt(words.size(),vector<int>(27,0));
        vector<int> val(n);
        
        for(int i=0;i<words.size();i++){
            int c=0;
            for(char &ch:words[i]){
                c++;
                cnt[i][ch-'a']++;
            }
            val[i]=c;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                bool ok=1;
                for(int k=0;k<27;k++){
                    if(cnt[i][k] && cnt[j][k]){
                        ok=0;
                        break;
                    }
                }
                if(ok) ans=max(val[i]*val[j],ans);
            }
        }
        return ans;
        
        
    }
};