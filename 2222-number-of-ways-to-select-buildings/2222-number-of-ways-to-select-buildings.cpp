class Solution {
public:
    long long numberOfWays(string s) {
        long long ans=0;
        
        vector<long long> one(s.size()+2,0);
        vector<long long> zero(s.size()+2,0);
        vector<long long> zero2(s.size()+2,0);
        vector<long long> one2(s.size()+2,0);
        for(int i=1;i<=s.size();i++){
            one[i]+=one[i-1]+(s[i-1]=='1');
            zero[i]+=zero[i-1]+(s[i-1]=='0');
        }
        for(int i=s.size();i>0;i--){
            one2[i]+=one2[i+1]+(s[i-1]=='1');
            zero2[i]+=zero2[i+1]+(s[i-1]=='0');
        }
        
        for(int i=1;i<=s.size();i++){
            if(s[i-1]=='0')
                ans+=(one[i-1]*one2[i+1]);
            else
                ans+=(zero[i-1]*zero2[i+1]);
        }
        return ans;
        
    }
};