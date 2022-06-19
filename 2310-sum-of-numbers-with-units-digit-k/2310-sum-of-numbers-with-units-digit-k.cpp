class Solution {
public:
    int minimumNumbers(int num, int k,int nx=1) {
        return num==0?0:((nx*k)%10 == (num%10) && nx*k<=num?nx:(nx<=3000?minimumNumbers(num,k,nx+1):-1));
    }
};