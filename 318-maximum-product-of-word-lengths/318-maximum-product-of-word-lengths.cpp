class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<vector<bool>> cnt(words.size(),vector<bool>(27,false));
        // vector<int> val(n);  
        for(int i=0;i<words.size();i++){
            // int c=0;
            for(char &ch:words[i]){
                // c++;
                cnt[i][ch-'a']=1;
            }
            // val[i]=c;
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
                // int val = 
                if(ok) ans=max((int)words[i].size()*(int)words[j].size(),ans);
            }
        }
        return ans;
    }
};