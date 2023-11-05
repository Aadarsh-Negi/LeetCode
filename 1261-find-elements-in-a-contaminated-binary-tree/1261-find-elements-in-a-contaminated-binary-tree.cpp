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
class FindElements {
public:
    unordered_map<int,int> isInTree;
    FindElements(TreeNode* root) {
        queue<TreeNode *> nodes;
        nodes.push(root);
        root->val = 0;
        while(!nodes.empty()){
            TreeNode *current = nodes.front();
            nodes.pop();
            isInTree[current->val] = 1;
            if(current->left){
                current->left->val = current->val*2 + 1;
                nodes.push(current->left);
            }
            
            if(current->right){
                current->right->val = current->val*2 + 2;
                nodes.push(current->right);
            }
        }
    }
    
    bool find(int target) {
        return isInTree[target];
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */