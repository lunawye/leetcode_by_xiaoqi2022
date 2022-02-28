/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    int deep(TreeNode *root, int d)
    {
        if (!root)
            return d;
        return max(deep(root->left, d + 1), deep(root->right, d + 1));
    }
    bool isBalanced(TreeNode *root)
    {
        if (!root)
            return true;
        return (abs(deep(root->left, 0) - deep(root->right, 0)) <= 1) && (isBalanced(root->right)) && (isBalanced(root->left));
    }
};