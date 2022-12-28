class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> qq(piles.begin(),piles.end());
        
        while(k--){
            int c = qq.top();
            // cout<<c<<" ";
            qq.pop();
            c-=c/2;
            qq.push(c);
        }
        int s=0;
        while(qq.size())s+=qq.top(),qq.pop();
        return s;
        
    }
};