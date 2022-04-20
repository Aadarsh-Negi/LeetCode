/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
public:
    stack<TreeNode*> ss;
    
    
    BSTIterator(TreeNode* root) {
        up(root);
    }
    void up(TreeNode *root){
        while(root){
            ss.push(root);
            root=root->left;
        }
    }
    
    int next() {
        TreeNode *val = ss.top();
        ss.pop();
        up(val->right);
        return val->val;
    }
    
    bool hasNext() {
        return ss.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */