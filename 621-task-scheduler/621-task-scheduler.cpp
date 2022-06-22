class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> f(26);
        int s=tasks.size();
        for(int i=0;i<s;++i)
            ++f[tasks[i]-'A'];
        sort(f.begin(),f.end());
        int max_gap=f[25]-1;
        int hole=(max_gap) * n;
        for(int i=24;i>=0;--i)
            hole-=min(max_gap,f[i]);
        return hole<0?s: s+hole;
    }
};