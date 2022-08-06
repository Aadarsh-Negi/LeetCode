class Solution {
public:
    int power(int x,int p){
        int px = 1;
        int res = 1;
        while(p){
            if(p&1) res*=x;
            x*=x;  
            p>>=1;
        }
        return res;
    }
    int poorPigs(int b, int m, int n) {
        int x=n/m+1,pig=0;
        while(power(x,pig)<b)pig++;
        return pig;
    }
};


// 1 > 15
// 2 > 15
// 3 > 15
// 4 > 15

//