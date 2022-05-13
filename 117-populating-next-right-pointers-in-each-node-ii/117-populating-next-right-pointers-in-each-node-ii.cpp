/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> nxt;
        
        nxt.push(root);
        
        while(nxt.size()){
            int n = nxt.size();
            Node *prev = nxt.front();
            nxt.pop();
            if(!prev) continue;
            nxt.push(prev->left);
            nxt.push(prev->right);
            for(int i=1;i<n;i++){
                Node *cur = nxt.front();
                nxt.pop();
                if(!cur) continue;
                nxt.push(cur->left);
                nxt.push(cur->right);
                prev->next = cur;
                prev=cur;
            }
            
        }
        return root;
    }
    
};