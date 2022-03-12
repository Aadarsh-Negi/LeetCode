/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // if(!head) return head;
        
        map<Node*,Node*> seen;
        
        Node* root = new Node(10);
        Node * cur=root;
        
        while(head){
            
            if(seen.count(head)) cur->next = seen[head];
            else cur->next = new Node(head->val),seen[head] = cur->next;
            
            if(head->random && seen.count(head->random)) cur->next->random = seen[head->random];
            else if(head->random) cur->next->random = new Node(head->random->val),seen[head->random] = cur->next->random;;
            
            
            cur=cur->next;
            head=head->next;
            
        }
        return root->next;
        
        
        
    }
};