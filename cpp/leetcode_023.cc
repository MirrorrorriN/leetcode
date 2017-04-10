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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        while (lists.size() > 1)
        {
            lists.push_back(mergeTwoLists(lists[0], lists[1]));
            lists.erase(lists.begin());
            lists.erase(lists.begin());
        }
        return lists[0];
    }

    ListNode* mergeTwoLists(ListNode* L1, ListNode* L2)
    {
        if (L1 == NULL)
            return L2;
        if (L2 == NULL)
            return L1;
        if (L1->val <=L2->val)
        {
            L1->next=mergeTwoLists(L1->next, L2);
            return L1;
        }
        else
        {
            L2->next = mergeTwoLists(L2->next, L1);
            return L2;
        }
    }
};