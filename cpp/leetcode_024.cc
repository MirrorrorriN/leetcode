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
    ListNode* swapPairs(ListNode* head) {

        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *temp;
        temp = head->next;
        head->next = swapPairs(temp->next);
        temp->next = head;
        return temp;
    }
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(0),*node;
        dummy->next = head;
        ListNode* pre = dummy, *cur = head;
        while (cur&&cur->next)
        {
            pre->next = cur->next;
            pre = pre->next;
            cur->next = pre->next;
            pre->next = cur;
            pre = cur;
            cur = cur->next;
        }
        return dummy->next;
    }
};