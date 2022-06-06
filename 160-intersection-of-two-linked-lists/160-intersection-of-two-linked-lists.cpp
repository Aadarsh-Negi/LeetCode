/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *A=headA;
        ListNode *B=headB;
        
        while(A!=B){
            if(A!=NULL) A=A->next;
            else A=headB;
            if(B!=NULL) B=B->next;
            else B=headA;
        }
        return A;
        
        
    }
};