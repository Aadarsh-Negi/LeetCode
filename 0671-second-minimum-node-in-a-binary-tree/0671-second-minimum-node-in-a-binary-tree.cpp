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
class Solution {
public:
    void findSmallest(TreeNode *root,int &minValue){
        if(!root) return;
        minValue = min(root->val,minValue);
        findSmallest(root->left,minValue);
        findSmallest(root->right,minValue);
    }
    void findSecondSmallest(TreeNode *root,int &minValue,int &secondMinValue){
        if(!root) return;
        if(root->val > minValue){
            if(secondMinValue == -1) secondMinValue = root->val;
            else secondMinValue = min(root->val,secondMinValue);
        }
            
        findSecondSmallest(root->left,minValue,secondMinValue);
        findSecondSmallest(root->right,minValue,secondMinValue);
    }
    int findSecondMinimumValue(TreeNode* root) {
        if(!root) return -1;
        int minValue = root->val;
        int secondMinValue = -1;
        findSmallest(root,minValue);
        findSecondSmallest(root,minValue,secondMinValue);
        return secondMinValue;
    }
};