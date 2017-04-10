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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode *p=head,*q=head;
        int n=0;
        while(p){
            n+=1;
            p=p->next;
        }
        
        if(n==0 || k==0) return head;
        n=k%n;
        if(n==0) return head;
        p=head;
        for(int i=0;i<n;i++){
            p=p->next;
        }
        ListNode* prep=NULL,* preq=NULL;
        while(p){
            if(p->next==NULL){
                prep=p;
                preq=q;
            }
            p=p->next;
            q=q->next;
        }
        if(preq!=NULL) preq->next=NULL;
        if(prep!=NULL) prep->next=head;
        return q;
    }
};