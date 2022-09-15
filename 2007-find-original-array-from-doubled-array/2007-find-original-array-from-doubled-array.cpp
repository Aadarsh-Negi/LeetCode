class Solution {
public:
    vector<int> findOriginalArray(vector<int>& ar) {
        multiset<int> cnt;
        
        for(int i:ar) cnt.insert(i);
        vector<int> ans;
        while(cnt.size()){
            int c = *cnt.begin(); cnt.erase(cnt.begin());
            if(cnt.find(c*2)!=cnt.end()) {cnt.erase(cnt.lower_bound(c*2)); ans.push_back(c);}
            else return {};
        }
        return ans;
        
    }
};