class Solution {
public:
    int coinChange(vector<int>& coins, int x) {
        queue<int> curStates;
        curStates.push(x);
        int const N = 1e4 + 55;
        int seen[N] = {0};
        
        int change = 0;
        while(!curStates.empty()){
            int size = curStates.size();
            while(size--){
                int amount = curStates.front();
                curStates.pop();
                if(amount == 0) return change;
                if(seen[amount]) continue;
                seen[amount] = 1;
                for(int i:coins){
                    if(i <= amount){
                        curStates.push(amount-i);
                    }
                }
            }
            change++;
        }
        return -1;
    }
};
