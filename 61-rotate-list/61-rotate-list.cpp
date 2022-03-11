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
    // Node* rotate(Node* head, int k)
    // {
    //     // int k=0;
    //     // Your code here
    // }
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return NULL;   
        ListNode *ans=head;
        // k++;
        ListNode *temp=head;
        int n=0;
        while(temp) temp=temp->next,n++;
        k%=n;    
        k=n-k;
        // cout<<n<<" "<<k<<"\n";
        k++;
        ListNode *cpy=ans;
        ListNode *fst=head;
        ListNode *prev=head;
        while(head){
            k--;
            if(k==0){
                prev->next=NULL;
                ans=head;
                
            }
            prev=head;
            head=head->next;
        }
        if(ans!=cpy)
        prev->next=fst;
        return ans;
        
    }
};