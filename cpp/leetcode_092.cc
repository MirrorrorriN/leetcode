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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m==n) return head;
        ListNode* res=new ListNode(0),*p=head,*pre=res,*start=res;
        res->next=head;
        for(int i=0;i<m-1;i++){
            pre=pre->next;
        }
        ListNode* cur=pre->next;
        for(int i=0;i<n-m;i++){
            ListNode* temp=cur->next;
            cur->next=temp->next;
            temp->next=pre->next;
            pre->next=temp;
        }
        return res->next;
    }
};