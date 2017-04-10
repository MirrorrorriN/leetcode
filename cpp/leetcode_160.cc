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
        ListNode *p=headA,*q=headB;
        while(p&&q){
            p=p->next;
            q=q->next;
        }
        if(p==nullptr){
            p=headB;
            while(q){
                p=p->next;
                q=q->next;
            }
            q=headA;
        }
        else{
            q=headA;
            while(p){
                p=p->next;
                q=q->next;
            }
            p=headB;
        }
        while(p){
            if(p==q) return p;
            p=p->next;
            q=q->next;
        }
        return NULL;
    }
};