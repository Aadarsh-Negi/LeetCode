class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string s) {
        vector<int> par(27,-1);
        
        auto find = [&](auto&&find,int x)->int{
            if(par[x] == -1) return x;
            return par[x]  = find(find,par[x]);       
        };
        int n = s1.size();
        for(int i=0;i<n;i++){
            int a = find(find,s1[i]-'a');
            int b = find(find,s2[i]-'a');
            if(a==b) continue;
            if(a > b) swap(a,b);
            par[b] = a;
        }
        
        for(char &c:s)
            c = 'a' + find(find,c-'a');
        
        return s;
        
    }
};