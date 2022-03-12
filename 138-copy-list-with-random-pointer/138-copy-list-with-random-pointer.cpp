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
        
        Node* root = NULL;
        Node * cur=NULL;
        
        while(head){
            
            
                if(seen.count(head)){
                    bool fl=0;
                    if(root==NULL) root=cur = seen[head],fl=1;
                    else cur->next = seen[head];
                    
                    if(fl){
                        if(head->random && seen.count(head->random)){
                            cur->random = seen[head->random];
                        }else if(head->random){
                            Node *temp = new Node(head->random->val);
                            seen[head->random] = temp;
                            cur->random = temp;
                        } 
                    }else{
                        if(head->random && seen.count(head->random)){
                            cur->next->random = seen[head->random];
                        }else if(head->random){
                            Node *temp = new Node(head->random->val);
                            seen[head->random] = temp;
                            cur->next->random = temp;
                        }
                        cur=cur->next;
                    }
                }else{
                    
                    bool fl=0;
                    if(root==NULL) root= cur = new Node(head->val),fl=1;
                    else cur->next = new Node(head->val);
                    
                    if(fl){
                        seen[head]= cur;
                        if(head->random && seen.count(head->random)){
                            cur->random = seen[head->random];
                        }else if(head->random){
                            Node *temp = new Node(head->random->val);
                            seen[head->random] = temp;
                            cur->random = temp;
                        } 
                    }else{
                        seen[head]= cur->next;
                        if(head->random && seen.count(head->random)){
                            cur->next->random = seen[head->random];
                        }else if(head->random){
                            Node *temp = new Node(head->random->val);
                            seen[head->random] = temp;
                            cur->next->random = temp;
                        }
                        cur=cur->next;
                    }
                    
                    
                    
                }
            head=head->next;
            
        }
        return root;
        
        
        
    }
};