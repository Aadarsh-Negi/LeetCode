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
    ListNode *reverse(ListNode * root){
        ListNode *prev=NULL;
        ListNode *next=NULL;
        
        while(root){
            next=root->next;
            root->next=prev;
            prev=root;
            root=next;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode *slow;
        ListNode *fast;
        slow=fast=head;
        
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode *h2=NULL;
        if(fast) h2=reverse(slow->next),slow->next=NULL;
        else{
            
            fast = head;
            while(fast->next!=slow) fast=fast->next;
            
            h2=reverse(slow);
            fast->next=NULL;
        }
        
        while(head && h2){
            if(head->val != h2->val) return 0;
            head=head->next;
            h2=h2->next;
        }
        return 1;
    
    }
};