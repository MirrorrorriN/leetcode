/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include<iostream>
#include<stack>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
class Solution {
public:
    void reorderList(ListNode* head) {
        if(head==nullptr||head->next==nullptr){
            return;
        }
        ListNode* p=head;
        ListNode* q=head;
        while(q->next!=nullptr){
            p=p->next;
            q=q->next->next;
        }
        ListNode* newHead=p->next;
        p->next=nullptr;
        stack<ListNode*> s;
        while(newHead!=nullptr){
            s.push(newHead);
            newHead=newHead->next;
        }
        p=head;
        while(!s.empty()){
            ListNode* curr=s.top();
            s.pop();
            curr->next=p->next;
            p->next=curr;
            p=p->next->next;
        }
        return;
    }
};