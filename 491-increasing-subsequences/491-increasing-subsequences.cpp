class Solution {
public:
    void solve(vector<int>&a , int i , vector<int>&v ,set<vector<int>>&s) {
      if(i == a.size()){
        if(v.size() > 1)
          s.insert(v);
          return;
      }
      
        // solve(a , i +1 , v, s);
      if(v.size()==0 or v[v.size()-1] <= a[i]) {
        v.push_back(a[i]);
        solve(a, i+1 , v, s);
        v.pop_back();
      }
         solve(a , i +1 , v, s);
    }
    vector<vector<int>> findSubsequences(vector<int>&a) {
      vector<vector<int>>ans;
      set<vector<int>>s;
      vector<int>v;
      solve(a, 0 , v ,s);
      for(auto j : s) ans.push_back(j);
      return ans;
    }
};