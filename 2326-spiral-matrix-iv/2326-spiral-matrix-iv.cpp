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
    vector<int> ar;
    void solve(ListNode *head){
        if(!head) return;
        ar.push_back(head->val);
        solve(head->next);
        
    }
    vector<vector<int>> spiralMatrix(int n, int m, ListNode* head) {
        solve(head);
        // while(ar.size()<n*m) ar.push_back(-1);
        
        vector<vector<int>> ans(n,vector<int>(m,-1));
         
        for(int i:ar) cout<<i<<" "; cout<<"\n";
        
        int num=0;
        
        int i=0;
        int j=0;
        
        int li=n;
        int lj=m;
        
        int fi=1;
        int fj=0;
        
        
        while(num<ar.size()){
            while(j<lj && num<ar.size()) ans[i][j++]=ar[num++];
            lj--;
            j--;
            i++;
            while(i<li && num<ar.size()) ans[i++][j]=ar[num++];
            i--;
            li--;
            j--;
            
            while(j>=fj && num<ar.size()) ans[i][j--]=ar[num++];
            j++;
            i--;
            fj++;
            while(i>=fi && num<ar.size()) ans[i--][j]=ar[num++];
            i++;
            j++;
            fi++;
            // fs++;
            
        }
        return ans;
        
    }
};