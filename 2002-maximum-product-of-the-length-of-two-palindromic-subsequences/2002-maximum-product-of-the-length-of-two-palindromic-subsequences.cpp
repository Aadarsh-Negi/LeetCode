class Solution {
public:
    int maxProduct(string s) {

        int n = s.size();
        vector<pair<int,int>> ans;
        for(int i=0;i<(1<<n);i++){
            string t;
            for(int j=0;j<n;j++){
                if(i&(1<<j)) t+=s[j];
            }
            string x = t;
            reverse(x.begin(),x.end());
            if(x == t){
                ans.push_back({i,x.size()});
            }
        }
        int val = 0;
        n = ans.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                bool f = 1;
                for(int k=0;k<12;k++){
                    if(((1<<k)&ans[i].first) && ((1<<k)&ans[j].first)){
                        f = 0;
                        break;
                    }
                }
                if(f) val = max(val,ans[i].second*ans[j].second);
            }
        }
        
        
        // for(int i:ans) cout<<i<<" ";cout<<"\n";
        return val;
        
    }
};