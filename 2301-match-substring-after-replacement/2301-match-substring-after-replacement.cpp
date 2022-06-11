class Solution {
public:
    bool matchReplacement(string &s2, string &s, vector<vector<char>>& mappings) {
        vector<string> subs;
        unordered_map<char,set<char>> sx;
        for(auto it:mappings){
            sx[it[0]].insert(it[1]);
            
        }
        // for(auto it:mp) cout<<it.first<<" "<<it.second<<"\n";
        
        for(int i=0;i<s2.size();i++){
            string temp;
            for(int j=i;j<s2.size();j++){
                temp+=s2[j];
                if(temp.size()==s.size())
                    subs.push_back(temp);
            }
        }
            int x = s.size();
        
        for(string &sub:subs){
            // cout<<s<<"\n";
            // if(s.size()==sub.size()){
                // set<pair<char,char>> used;        
                bool ok=1;
                for(int i=0;i<x;i++){
                    if(s[i]==sub[i]);
                    else{
                       if(sx[s[i]].count(sub[i])){
                           // used.insert({s[i],sub[i]});
                       }
                       else {
                           ok=0;
                           break;
                       }
                    }
                }
            // if(ok) cout<<sub<<"\n";
                if(ok) return 1;
                
            // }
        }
        
        // for(string s:subs) cout<<s<<"\n";
        return 0;
    }
};