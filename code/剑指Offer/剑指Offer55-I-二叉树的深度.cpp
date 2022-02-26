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
    int deep(TreeNode *root, int Deep)
    {
        if (!root)
            return Deep;
        else
            return max(deep(root->left, Deep + 1), deep(root->right, Deep + 1));
    }
    int maxDepth(TreeNode *root)
    {
        if (!root)
            return 0;
        else
            return deep(root, 0);
    }
};