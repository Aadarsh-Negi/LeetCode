class Solution {
public:
    template <class T, class F = function<T(const T &, const T &)>>
struct SparseTable {
    vector<vector<T>> t;
    F func;

    SparseTable(const vector<T> &a, F f) : t(32 - __builtin_clz(a.size())), func(std::move(f)) {
        t[0] = a;
        for (size_t i = 1; i < t.size(); i++) {
            t[i].resize(a.size() - (1 << i) + 1);
            for (size_t j = 0; j < t[i].size(); j++)
                t[i][j] = func(t[i - 1][j], t[i - 1][j + (1 << (i - 1))]);
        }
    }

    T get(int from, int to) const {
        assert(0 <= from && from <= to && to <= (int)t[0].size() - 1);
        int k = 31 - __builtin_clz(to - from + 1);
        return func(t[k][from], t[k][to - (1 << k) + 1]);
    }
};
    vector<int> secondGreaterElement(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> ans;
        SparseTable<int> mx(nums, [](int i, int j) { return max(i, j); });
        
        auto find = [&](int k,int lx){
            int l = lx;
            int r = n-1;
            int t = -1;
            while(l<=r){
                int mid = l + (r-l)/2;
                int q = mx.get(lx,mid);
                if(q>k){
                    t = mid;
                    r = mid-1;
                }else l = mid+1;
            }
            return t;
        };
        
        for(int i=0;i<n;i++){
            int f = find(nums[i],i+1);
            if(f!=-1){
                f = find(nums[i],f+1);
            }
            if(f!=-1) f = nums[f];
            ans.push_back(f);
        }
        return ans;
        
    }
};