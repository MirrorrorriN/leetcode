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
    ListNode* partition(ListNode* head, int x) {
        ListNode l(0),r(0);
        ListNode* left=&l,*right=&r,*p=head;
        while(p){
            if(p->val<x){
                ListNode temp(p->val);
                left->next=p;
                left=left->next;
            }
            else{
                ListNode temp(p->val);
                right->next=p;
                right=right->next;
            }
            p=p->next;
        }
        left->next=r.next;
        right->next=NULL;
        return l.next;
    }
};
