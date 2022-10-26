class Solution {
public:
    bool checkSubarraySum(vector<int>& ar, int k) {
        for(int &i:ar) i%=k;
        int n = ar.size();
        if(n<2) return 0;
        unordered_map<int,int> seen;
        seen[0] = 0;
        int ss = 0;
        for(int i=0;i<n;i++){
            ss+=ar[i];
            ss%=k;
            if(!seen.count(ss))
                    seen[ss]=i+1;
            else if(seen[ss]<i) return 1;
        }
        return false;
    }
};