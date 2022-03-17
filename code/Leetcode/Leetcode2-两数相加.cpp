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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int ans = 0;
        ListNode *l = new ListNode(-1);
        ListNode *head = l;
        while (l1 || l2)
        { //用两个分开记录数值可以避免l1 l2是否是空的分类
            int l1_value = 0;
            int l2_value = 0;
            if (l1)
            {
                l1_value = l1->val;
                l1 = l1->next;
            }
            if (l2)
            {
                l2_value = l2->val;
                l2 = l2->next;
            }
            ListNode *node = new ListNode((l1_value + l2_value + ans) % 10);
            l->next = node;
            l = l->next;
            ans = ((l1_value + l2_value + ans) / 10);
        }
        if (ans)
        {
            ListNode *node = new ListNode(ans);
            l->next = node;
        }
        return head->next;
    }
};