class Solution {
public:
    int minDeletions(string s) {
        // set<int> ix;
        // for(int i=0;i<=s.size();i++) ix.insert(i);
        vector<int> freq(26,0);
        for(char &c:s){
            freq[c-'a']++;
        }
        int ans=0;
        sort(freq.rbegin(),freq.rend());
        int prev=-1;
        for(int &i:freq){
            if(!i) break;
            if(prev==-1) prev = i;
            else{
                if(prev<=i){
                    ans+= i - max(0,(prev-1));
                    i = max(0,prev-1);
                    // i =
                }
            }
            prev=i;
            // cout<<prev<<" ";
        }
//         for(int i:freq){
//             if(i){
//                 auto it = ix.upper_bound(i); it--;
                
//                 ans+=abs(i-*it);
//                 ix.erase(it);
                
//             }
//         }
        return ans;
        
    }
};