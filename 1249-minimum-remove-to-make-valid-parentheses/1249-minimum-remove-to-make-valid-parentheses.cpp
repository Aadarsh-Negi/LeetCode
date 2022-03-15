class Solution {
public:
    string minRemoveToMakeValid(string s) {
        set<int> ar;
        int n=s.size();
        set<int> inv;
        for(int i=0;i<n;i++){
            char c = s[i];
            if(c=='(') ar.insert(-(i+1));
            else if(c==')') if(ar.size()) ar.erase(ar.begin()); else inv.insert(i);
        }
        string ans;
        for(int i=0;i<n;i++){
            if(inv.count(i)) continue;
            if(ar.count(-(i+1))) continue;
            ans+=s[i];
        }
        return ans;
        
        
    }
};