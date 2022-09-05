/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        queue<Node *> qq;
        if(root)
            qq.push(root);
        while(qq.size()){
            int x = qq.size();
            vector<int> temp;
            while(x--){
                Node *cur = qq.front(); qq.pop();
                temp.push_back(cur->val);
                for(Node *s:cur->children){
                    if(s) qq.push(s);
                }
            }
            if(temp.size()) ans.push_back(temp);
        }
        return ans;
    }
};