class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode*curr = head, *back = head, *front = head;
        
        int i = 0;
        while(curr != NULL) {
            i++;
            curr = curr->next;
            if(i > k) back = back->next;
            if(i < k) front = front->next;
        }
        int v=front->val;
        front->val=back->val;
        back->val=v;
        // swap(front->val, back->val);
        return head;
    }
};