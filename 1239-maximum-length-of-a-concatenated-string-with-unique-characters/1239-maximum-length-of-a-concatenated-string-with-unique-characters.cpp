class Solution {
public:
    int n ,ans = 0;
    bool isvalid( string&s, int &mask) {
       for(auto it : s) {
          if(mask&(1<<(it-'a'))) return false;
          mask = mask|(1<<(it-'a'));
       }
      return true;
    }
    void solve(vector<string>&a , int i , int mask , int temp) {
       ans = max(ans , temp);
       if(i>=n) return;
       
          int tmask = mask;
          if(isvalid(a[i],tmask)) 
            solve(a,i+1,tmask,temp+a[i].size());
          
             solve(a,i+1,mask,temp);
       
    }
    int maxLength(vector<string>& a) {
         n = a.size();
        solve(a,0,0,0);
       return ans;
    }
};