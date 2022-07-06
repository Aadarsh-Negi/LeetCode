class Solution {
public:
    unordered_map<int,int> ax;
    int fib(int n) {
        return ax[n]!=0 ? ax[n] : n<=1 ? n : ax[n] = fib(n-1) + fib(n-2);
    }
};