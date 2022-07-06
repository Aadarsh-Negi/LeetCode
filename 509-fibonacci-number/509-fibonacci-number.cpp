vector<int> ax(33,-1);
class Solution {
public:
    int fib(int n) {
        return ax[n]!=-1 ? ax[n] : n<=1 ? n : ax[n] = fib(n-1) + fib(n-2);
    }
};