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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *p = head,*temp,*pre,*succ;
        for(int i=0;i<k;i++)
        {
            if (p == nullptr) return head;
            p = p->next;
        }
        temp = head->next;
        head->next = reverseKGroup(p,k);
        pre = head;
        for (int i = 1; i < k; i++)
        {
            succ = temp->next;
            temp->next = pre;
            pre = temp;
            temp = succ;
        }
        return pre;
    }
};