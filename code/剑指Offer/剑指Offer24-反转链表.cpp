/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *curr = head;
        ListNode *p = NULL;
        while (curr)
        {
            ListNode *temp = curr->next;
            curr->next = p;
            p = curr;
            curr = temp;
        }
        return p;
    }
};