/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *p = list1;
        ListNode *q = list2;
        ListNode *head = new ListNode(-1);
        ListNode *fake_head = head;
        while (p && q)
        {
            if (p->val <= q->val)
            {
                fake_head->next = p;
                fake_head = fake_head->next;
                p = p->next;
            }
            else
            {
                fake_head->next = q;
                fake_head = fake_head->next;
                q = q->next;
            }
        }
        if (p)
            fake_head->next = p;
        else
            fake_head->next = q;
        return head->next;
    }
};