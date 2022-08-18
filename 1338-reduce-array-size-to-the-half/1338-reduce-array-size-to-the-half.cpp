class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int const N = 1e5 + 15;
        int cnt[N] = {0};
        for(int &i:arr) cnt[i]++;
        sort(cnt,cnt+N);
        reverse(cnt,cnt+N);
        int cur=0;
        for(int i=0;i<N;i++){
            cur+=cnt[i];
            if(cur>=(arr.size()/2)) return i+1;
        }
        return N;
        
    }
};