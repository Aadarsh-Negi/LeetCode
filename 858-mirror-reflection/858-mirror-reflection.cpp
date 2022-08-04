class Solution {
public:
    int mirrorReflection(int p, int q) {
        return (p%2==0 && q%2==0)?mirrorReflection(p/2,q/2):(1- p%2 + q%2);
    }
};