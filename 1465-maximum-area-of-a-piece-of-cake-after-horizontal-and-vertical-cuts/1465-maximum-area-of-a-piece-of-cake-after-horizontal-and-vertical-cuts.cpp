int const mod = 1e9 + 7;
class Solution {
public:
    int ans(vector<int> &ar){
        sort(ar.begin(),ar.end());
        int mx=-1;
        int prev=0;
        for(int i=0;i<ar.size();i++) mx=max(mx,ar[i]-prev),prev=ar[i];
        
        return mx;
    }
    int maxArea(int i, int j, vector<int>& h, vector<int>& v) {
        h.push_back(i);
        v.push_back(j);
        return 1LL*ans(h)*ans(v)%mod;
    }
};