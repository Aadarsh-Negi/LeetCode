class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& ar) {
        vector<vector<int>> ans;
        sort(ar.begin(),ar.end());
        int n = ar.size();
        
        set<vector<int>> temp;
        for(int i=0;i<n;i++){
            if(i>0 && ar[i]==ar[i-1]) continue;
            int v = ar[i];
            int l = i+1;
            int r = n-1;
            while(l<r){
                int val = v + ar[l] + ar[r];
                if(val==0){
                    temp.insert({v,ar[l],ar[r]});
                    l++;
                    r--;
                }else if(val > 0) r--;
                else l++;
            }
        }
        
        
        for(auto it:temp)
            ans.push_back(it);
        
        return ans;
        
    }
};