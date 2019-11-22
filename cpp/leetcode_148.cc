#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head==nullptr||head->next==nullptr){
            return head;
        }else{
            ListNode *fast=head;
            ListNode *slow=head;
            while(fast->next!=nullptr
            &&fast->next->next!=nullptr){
                fast=fast->next->next;
                slow=slow->next;
            }
            fast=slow;
            slow=slow->next;
            fast->next=nullptr;
            fast=sortList(head);
            slow=sortList(slow);
            return merge(fast,slow);
        }
    }

    ListNode* merge(ListNode* h1,ListNode* h2){
        if(h1==nullptr){
            return h2;
        }
        if(h2==nullptr){
            return h1;
        }
        ListNode *head,*p;
        if(h1->val>h2->val){
            head=h2;
            h2=h2->next;
        }else{
            head=h1;
            h1=h1->next;
        }
        p=head;
        while(h1!=nullptr&&h2!=nullptr){
            if(h1->val>h2->val){
                h2=h2->next;
                p->next=h2;
            }else{
                h1=h1->next;
                p->next=h1;
            }
            p=p->next;
        }
        if(h1!=nullptr){
            p->next=h1;
        }
        p->next=h2;
        return head;
    }
};