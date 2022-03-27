class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
       
        
     vector<pair<int,int>> ar;
        int ind=0;
        for(auto it:mat){
            int o1=0;
            for(int i:it) o1+=(i==1);
            ar.push_back({o1,ind});
            ind++;
        }
    sort(ar.begin(),ar.end(),[&](pair<int,int> &a,pair<int,int> &b){
        if(a.first == b.first) return a.second<b.second;
        return a.first<b.first;
    });
    vector<int> ans;
    for(int i=0;i<k;i++) ans.push_back(ar[i].second);
    return ans;
        
    }
    
};