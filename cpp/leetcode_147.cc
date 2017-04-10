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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* newHead=new ListNode(0),*p=head;
        while(p){
            ListNode* s=new ListNode(p->val);
            ListNode* q=newHead->next,*pre=newHead;
            if(q==nullptr){
                q=s;
                newHead->next=s;
            }
            else
            {
                while(q&&q->val<p->val){
                    pre=q;
                    q=q->next;
                }
            
                s->next=pre->next;
                pre->next=s;
            }
            p=p->next;
            
        }
        ListNode* res=newHead->next;
        delete newHead;
        return res;
    }
};