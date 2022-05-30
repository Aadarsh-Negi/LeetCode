#define all(xxx90) xxx90.begin(),xxx90.end()
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int ans=0;
        
        vector<pair<int,int>> val;
        
        int i=0;
        
        for(string &s:words){
            vector<int> cnt(27,0);
            for(char &c:s) cnt[c-'a']++;
            int res=0;
            for(int j=0;j<27;j++){
                // cout<<cnt[j]<<" ";
                if(cnt[j]){
                    res|=(1<<j);
                } 
            }
            // cout<<res<<" ";
            val.push_back({res,s.size()});
            i++;
        }
        i=0;
        int n = words.size();
        for(;i<n;i++){
            int x = val[i].first;
            int wt = val[i].second;
            for(int j=i+1;j<n;j++){
                int y = val[j].first;
                int wt2 = val[j].second;
                if((x&y)==0){
                    ans=max(ans,wt*wt2);
                }
            }
        }
                          // return ans;
        
        
        return ans;
    }
};