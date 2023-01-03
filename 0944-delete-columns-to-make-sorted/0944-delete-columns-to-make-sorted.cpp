class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int ans=0;
        int n = strs[0].size();
        vector<int> mn(n,-1);
        for(string &s:strs){
            int i=0;
            for(char &c:s){
                if(mn[i]==-2) {i++; continue;}
                if(mn[i] > c){
                    mn[i] = -2;
                    ans++;
                }else
                    mn[i] = c;
                i++;
            }
        }
            
        return ans;
    }
};