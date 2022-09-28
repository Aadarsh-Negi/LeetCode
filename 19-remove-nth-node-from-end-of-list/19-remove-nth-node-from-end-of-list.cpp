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
   
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int i=0;
        ListNode *temp=head;
        ListNode *prev=head;
        while(temp){
            i++;
            if(i>(n+1)) prev=prev->next;
            temp=temp->next;
        }
        if(i==n) return prev->next;
        
        prev->next=prev->next->next;
        return head;
         
        
    }
};