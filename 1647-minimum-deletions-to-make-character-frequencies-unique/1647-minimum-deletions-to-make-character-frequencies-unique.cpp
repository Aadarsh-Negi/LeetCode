class Solution {
public:
    int minDeletions(string s) {
        set<int> ix;
        for(int i=0;i<=s.size();i++) ix.insert(i);
        vector<int> freq(26,0);
        for(char &c:s){
            freq[c-'a']++;
        }
        int ans=0;
        for(int i:freq){
            if(i){
                auto it = ix.upper_bound(i); it--;
                
                ans+=abs(i-*it);
                if(*it != 0) ix.erase(it);
                
            }
        }
        return ans;
        
    }
};