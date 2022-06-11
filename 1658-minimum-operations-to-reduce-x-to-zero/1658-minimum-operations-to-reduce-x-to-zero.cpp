class Solution {
public:
    int minOperations(vector<int>& ar, int x) {
        int t=0;
        for(int &i:ar) t+=i;
        t-=x;
        int i=0;
        int len=0;
        int mx=-1;
        while(i<ar.size()){
            t-=ar[i];
            while(t<0 && len<=i) t+=ar[len++];
            if(t==0) mx = max(mx,i-len+1);
            i++;
        }
        return mx==-1?mx:ar.size()-mx;
    }
};