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
    ListNode* partition(ListNode* head, int x) {
        ListNode *fs = nullptr;
        ListNode *ls = nullptr;
        ListNode *temp = nullptr;
        ListNode *temp2 = nullptr;
        while(head){
            if(head->val < x){
                if(fs) temp->next = head,temp = temp->next;
                else fs = temp = head;
            }else{
                if(ls) temp2->next = head,temp2 = temp2->next;
                else ls = temp2 = head;
            }
            head=head->next;
        }
        if(fs) temp->next = ls;
        else fs = ls;
        
        if(ls) temp2->next = nullptr;
        
        
//         while(fs) cout<<fs->val<<" ",fs=fs->next;cout<<"\n\n";
//         while(ls) cout<<ls->val<<" ",ls=ls->next;cout<<"\n\n";
        
        return fs;
        
    }
};