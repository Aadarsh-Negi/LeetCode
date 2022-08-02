class Solution {
public:
    int kthSmallest(vector<vector<int>>& ar, int k) {
        priority_queue<int> qq;
        
        for(auto &it:ar) for(int &i:it){
            qq.push(i);
            if(qq.size() > k) qq.pop();
        }
        return qq.top();
    }
};