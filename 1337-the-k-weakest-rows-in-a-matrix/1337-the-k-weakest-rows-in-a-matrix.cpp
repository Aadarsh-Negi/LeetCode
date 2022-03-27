class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> ans;
        
        map<int,vector<int>> cnt;
        int ind=0;
        for(auto &it:mat){
            int o1=0;
            for(int &i:it) o1+=(i==1);
            cnt[o1].push_back(ind);
            ind++;
        }
        
        for(auto it:cnt){
            for(int i:it.second){
                ans.push_back(i);
                k--;
                
                if(!k) return ans;
            }
            
        }
        return {};
    
        
    }
    
};