class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& qq) {
        vector<int> ans;
        
        vector<int> pref = {0};
        string tt = "aeiou";
        for(string s:words){
            char c = s.back();
            char c2 = s.front();
            int t=(tt.find(c)!=string::npos && tt.find(c2)!=string::npos);
            pref.push_back(t+pref.back());
        }
        for(auto it:qq){
            int l = it[0];
            int r = it[1]+1;
            ans.push_back(pref[r]-pref[l]);
        }
        
        
        return ans;
    }
};