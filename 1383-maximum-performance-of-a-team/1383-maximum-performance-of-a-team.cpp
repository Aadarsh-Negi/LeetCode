template<class T> using mnpq = priority_queue<T, vector<T>, greater<T>>;
class Solution {
public:
    int maxPerformance(int n, vector<int>& spp, vector<int>& eff, int k) {
        mnpq<long long> qq;
        vector<int> idx(n);
        iota(idx.begin(),idx.end(),0);
        
        sort(idx.begin(),idx.end(),[&](int &a,int &b){
            // if(eff[a] == eff[b]) return spp[a] < spp[b];
                return eff[a] > eff[b];
        });
        long long ans = 0;
        long long const mod = 1e9 + 7;
        long long ss=0;
        for(int j=0;j<n;j++){
            int i = idx[j];
            qq.push(spp[i]);
            ss+=spp[i];
            // ss%=mod;
            if(qq.size()>k){
                ss-=qq.top();
                // while(ss<0) ss+=mod;
                // ss%=mod;
                qq.pop();
            }
            long long val = eff[i];
            val*=ss;
            // val%=mod;
            ans = max(ans,val);
        }
        return ans%mod;
    }
};