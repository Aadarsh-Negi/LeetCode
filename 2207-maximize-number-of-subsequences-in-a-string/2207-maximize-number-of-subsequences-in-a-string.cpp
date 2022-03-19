class Solution {
public:
    long long maximumSubsequenceCount(string text, string p) {
        
        
        long long ans=0;
        
        
        
        
        int n=text.size();
        
        map<char,int> cnt;
        for(int i=n-1;i>=0;i--){
            if(text[i]==p[0]){
                ans+=cnt[p[1]];
            }
            cnt[text[i]]++;
        }    
        ans= max(ans + cnt[p[0]], ans+cnt[p[1]]);
        
        // cout<<ans<<"\n";
        
        
        return ans;
        
        
        
        
        
        
    }
};