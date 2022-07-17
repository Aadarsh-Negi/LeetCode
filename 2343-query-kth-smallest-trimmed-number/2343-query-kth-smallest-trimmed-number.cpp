class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& ar, vector<vector<int>>& q) {
        
        vector<vector<pair<string,int>>> part(ar[0].size()+2);
        vector<int> ans;
        for(int i=0;i<ar.size();i++){
            string s = ar[i];
            string temp;
            int c=1;
            for(int j=s.size()-1;j>=0;j--){
                temp = s[j] + temp;
                part[c].push_back({temp,i});
                c++;
            }
        }
        
        
        for(auto &it:part){
            // for(auto ix:it){
            //     cout<<ix.first<<" "<<ix.second<<"\n";
            // }
            // cout<<"\n";
            sort(it.begin(),it.end());
        }
        
        for(auto it:q){
            int c = it[1];
            int k = it[0];
            // cout<<c<<" "<<k<<" "<<part[c].size()<<" >";
            // for(pair<string,int> i:part[c]) cout<<i.first<<" "<<i.second<<" >"<<" ";cout<<"\n";
            
            ans.push_back((part[c][k-1].second));
        }
        return ans;
        
    }
};