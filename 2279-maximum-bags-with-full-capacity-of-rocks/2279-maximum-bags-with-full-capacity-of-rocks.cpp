class Solution {
public:
    int maximumBags(vector<int>& full, vector<int>& cur, int xtra) {
        
        vector<int> req;
        
        for(int i=0;i<cur.size();i++){
            req.push_back(abs(cur[i]-full[i]));
        }
        sort(req.begin(),req.end());
        int ans=0;
        for(int i:req){
            if(i<=xtra) ans++,xtra-=i;
            else break;
        }
        return ans;
        
    }
};