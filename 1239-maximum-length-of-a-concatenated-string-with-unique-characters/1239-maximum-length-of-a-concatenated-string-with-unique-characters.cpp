class Solution {
public:
    int maxLength(vector<string>& ar) {
        int ans = 0;
        int n = ar.size();
        for(int i=0;i<(1<<n);i++){
            int cnt[27] = {0};
            bool ok=1;
            int temp=0;
            for(int j=0;j<n && ok;j++){
                if((1<<j)&i){
                    for(char &c:ar[j]){
                        cnt[c-'a']++;
                        temp++;
                        if(cnt[c-'a']>1){
                            ok=0;
                            break;
                        }
                    }    
                }
            }
            if(ok) ans = max(ans,temp);
        }
        
        return ans;
        
    }
};