#define ll long long
class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        int ans = -1;
        map<int,int> dd;
        for(int i:nums){
            int v = i%space;
            dd[v]++;
            if(dd[ans] < dd[v]) ans = v; 
        }
        int mn = INT_MAX;
        for(int i:nums){
            if(dd[ans]==dd[i%space]) mn = min(mn,i);
        }
        ans = mn;
        
        return ans;
        
        
    }
};