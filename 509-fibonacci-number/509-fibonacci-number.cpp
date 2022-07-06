class Solution {
public:
    int fib(int n,int i=0,int j=1) {
        return n==0 ? i : fib(n-1,j,i+j);
    }
};