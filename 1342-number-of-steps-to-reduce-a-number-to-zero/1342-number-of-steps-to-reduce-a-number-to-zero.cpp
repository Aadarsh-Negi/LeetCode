class Solution {
public:
    int solve(int num){
        if(num==0) return 0;
        
        return 1+(num&1 ? solve(num-1):solve(num>>1));
    }
    
    int numberOfSteps(int num) {
      return solve(num);
    }
};