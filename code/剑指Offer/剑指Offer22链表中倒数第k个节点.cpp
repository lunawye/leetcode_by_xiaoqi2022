/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//version1
/*
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode *root=head;
        int sum=0;
        while(root)
        {
            root=root->next;
            sum++;
        }
        while(head)
        {
            if(sum==k) return head;
            head=head->next;
            sum--;
        }
        return nullptr;
    }
};
*/
//version2
class Solution
{
public:
    ListNode *getKthFromEnd(ListNode *head, int k)
    {
        ListNode *fast = head;
        ListNode *slow = head;
        for (int i = 0; i < k && fast; i++)
        {
            fast = fast->next;
        }
        while (fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};
