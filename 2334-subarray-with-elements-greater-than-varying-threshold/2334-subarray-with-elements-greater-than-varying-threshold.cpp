class Solution {
public:
    int validSubarraySize(vector<int>& ar, int ts) {
        vector<int> nxt;
        int n = ar.size();
        ar.push_back(0);
        // nxt.push_back(n-1);
        for(int i=0;i<=n;i++){
            while(nxt.size() && ar[nxt.back()] > ar[i]){
                int v = ar[nxt.back()]; nxt.pop_back();
                int j = nxt.size()==0 ? -1 : nxt.back();
                if (v*(i-j-1) > ts)
                return i-j-1;
            }
            nxt.push_back(i);
            
        }
        // for(int i:nxt) cout<<i<<" ";
        return -1;
        
    }
};