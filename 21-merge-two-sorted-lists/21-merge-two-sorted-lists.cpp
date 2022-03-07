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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head=NULL;

        if(!l1 && l2) return l2;
        if(!l2 && l1) return l1;
        if(!l2 && !l1) return NULL;
        
        
        ListNode *cur=NULL;
        while(l1 && l2){
            ListNode* temp=new ListNode();
            if(l1->val > l2->val){
                temp->val=l2->val;
                if(!head) {head=temp; cur=head;}
                else {
                    cur->next=temp;
                    cur=cur->next;
                }
                l2=l2->next;
            }else{
                temp->val=l1->val;
                if(!head) {head=temp; cur=head;}
                else {
                    cur->next=temp;
                    cur=cur->next;
                }
                l1=l1->next;
            }
        }
        
        
        while(l1){
            ListNode *temp=new ListNode();
            temp->val=l1->val;
            l1=l1->next;
            cur->next=temp;
            cur=cur->next;
        }
        while(l2){
            ListNode *temp=new ListNode();
            temp->val=l2->val;
            l2=l2->next;
            cur->next=temp;
            cur=cur->next;
        }
        
         
        return head;
            
    }
};