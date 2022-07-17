class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& ar, vector<vector<int>>& q) {
        
        vector<pair<string,int>> part;
        vector<int> ans;
        for(int i=0;i<ar.size();i++){
            // string s = ar[i];
            // string temp;
            // int c=1;
            // for(int j=s.size()-1;j>=0;j--){
            //     temp = s[j] + temp;
                part.push_back({ar[i],i});
            //     c++;
            // }
        }
        
        
        // for(auto &it:part){
        //     // for(auto ix:it){
        //     //     cout<<ix.first<<" "<<ix.second<<"\n";
        //     // }
        //     // cout<<"\n";
        //     sort(it.begin(),it.end());
        // }
        int n = ar[0].size();
        
        for(auto it:q){
            int c = it[1];
            int k = it[0];
            // cout<<c<<" "<<k<<" "<<part[c].size()<<" >";
            // for(pair<string,int> i:part[c]) cout<<i.first<<" "<<i.second<<" >"<<" ";cout<<"\n";
            nth_element(begin(part), begin(part) + k - 1, end(part), [&](const auto &a, const auto &b){
            int cmp = a.first.compare(n - c, string::npos, b.first, n - c, string::npos);
            return cmp == 0 ? a.second < b.second : cmp < 0;
        });
            ans.push_back((part[k-1].second));
        }
        return ans;
        
    }
};