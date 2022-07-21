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
    ListNode *nxt = nullptr;
    ListNode *reverseList(ListNode *head, int n) {
        if (n == 1) {
            nxt = head->next;
            return head;
        }
        ListNode *last = reverseList(head->next, n - 1);
        head->next->next = head;
        head->next = nxt;
        return last;
    }    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
      if (left == 1) {
            return reverseList(head, right);
        }
        head->next = reverseBetween(head->next, left - 1, right - 1);
        return head;
        
    }
};