
class Solution {
public:
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
        map < char , set <int> > maps;
        for(auto a : mappings) {
            maps[a[0]].insert(a[1]);
        }
        int n = s.size() , m = sub.size();
        for(int i = 0;i<n;i++){
            int j = 0;
            for(;j<m;j++){
                if(i + j >= n)
                    break;
                if(s[i + j] == sub[j])
                    continue;
                if(maps[sub[j]].find(s[i + j]) == maps[sub[j]].end())
                    break;
            }
            if(j == m)
                return true;
        }
        return false;
    }
};