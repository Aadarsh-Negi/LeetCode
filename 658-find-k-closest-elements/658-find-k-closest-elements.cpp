class Solution {
public:
    vector<int> findClosestElements(vector<int>& ar, int k, int x) {
        vector<int> ans;
        vector<pair<int,int>> cnt;
        for(int i=0;i<ar.size();i++){
            cnt.push_back({abs(ar[i]-x),ar[i]});
        }
        sort(cnt.begin(),cnt.end(),[&](pair<int,int> &a,pair<int,int> &b){
           if(a.first==b.first) return a.second<b.second;
            return a.first<b.first;
        });
        for(int i=0;i<k;i++) ans.push_back(cnt[i].second);
        sort(ans.begin(),ans.end());
        return ans;
        
        
        
    }
};