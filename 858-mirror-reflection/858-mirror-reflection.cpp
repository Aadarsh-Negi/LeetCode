class Solution {
public:
    int mirrorReflection(int &p, int &q) {
        return (p&1) || (q&1)?1- (p&1) + (q&1):mirrorReflection(p>>=1,q>>=1);
    }
};