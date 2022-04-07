class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> qq(stones.begin(),stones.end());
        
        while(qq.size()>1){
            int y = qq.top(); qq.pop();
            int x = qq.top(); qq.pop();
            if(x!=y) qq.push(y-x);
        }
        return qq.size()==0?0:qq.top();
    }
};