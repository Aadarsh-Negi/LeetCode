class Solution {
public:
    int fib(int n,int i=0,int j=1) {
        while(n){
            int ix = i;
            i = j;
            j = ix + j;
            n--;
        }
        return i;
    }
};