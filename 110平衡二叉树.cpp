/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int judge(TreeNode *root, int deep)
    {
        if (!root)
            return deep;
        return max(judge(root->right, deep + 1), judge(root->left, deep + 1));
    }
    bool judgeEvery(TreeNode *root)
    {
        if (!root)
            return true;
        int left = judge(root->left, 0);
        int right = judge(root->right, 0);
        if (left - right > 1 || right - left > 1)
            return false;
        return true;
    }
    bool isBalanced(TreeNode *root)
    {
        if (!root)
            return true;
        return judgeEvery(root) && isBalanced(root->left) && isBalanced(root->right);
    }
};