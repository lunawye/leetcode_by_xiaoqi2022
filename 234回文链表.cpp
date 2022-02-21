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
    bool isPalindrome(ListNode *head)
    {
        ListNode *p = head;
        string res1 = "";
        while (p)
        {
            res1 += p->val + '0';
            p = p->next;
        }
        string res2 = res1;
        reverse(res1.begin(), res1.end());
        for (int i = 0; i < res1.length(); i++)
        {
            if (res1[i] != res2[i])
                return false;
        }
        return true;
    }
};