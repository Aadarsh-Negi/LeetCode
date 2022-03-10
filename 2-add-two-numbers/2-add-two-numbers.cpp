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
    
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            int cur=0;
            ListNode *root=new ListNode(-1);
            ListNode *temp=root;
        while(l1 && l2){
            int num=l1->val + l2->val +cur;
            
            if(num>=10){
                cur = num/10;
                if(temp->val==-1){
                    temp->val = num%10;
                }else{
                    temp->next= new ListNode(num%10);
                    temp=temp->next;
                }
            }else{
                cur=0;
                if(temp->val==-1){
                    temp->val = num%10;
                }else{
                    temp->next= new ListNode(num%10);
                    temp=temp->next;
                }
            }
            l1=l1->next;
            l2=l2->next;
        }
        if(l1) l2=l1;
            while(l2){
            int num=l2->val + cur;
            
            if(num>=10){
                cur = num/10;
                if(temp->val==-1){
                    temp->val = num%10;
                }else{
                    temp->next= new ListNode(num%10);
                    temp=temp->next;
                }
            }else{
                cur=0;
                if(temp->val==-1){
                    temp->val = num%10;
                }else{
                    temp->next= new ListNode(num%10);
                    temp=temp->next;
                }
            }
            l2=l2->next;
        }
        if(cur) temp->next = new ListNode(cur);
        return root;
        
    }
};