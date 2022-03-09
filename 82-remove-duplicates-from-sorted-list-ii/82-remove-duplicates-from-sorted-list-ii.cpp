/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return head;
       
        ListNode *root =NULL;
        ListNode *cur=root;
        while(head){
           
            int cur_val=head->val;
            ListNode*temp=head->next;
            int f=0;
            while(temp){
                if(temp->val==cur_val)  f=1;
                else    break;
                temp=temp->next;
            }
            if(!f){
                if(root)    
                    cur->next=head,cur=cur->next;
                else    root=cur=head;
            }
            
            head=temp;
            
            
        }
        if(root)    cur->next=NULL;
        
        
       
        return root;
        
        
    }
};