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
    int find(TreeNode *root, int deep)
    {
        if (!root)
            return deep;
        return max(find(root->left, deep + 1), find(root->right, deep + 1));
    }
    int maxDepth(TreeNode *root)
    {
        if (!root)
            return 0;
        return find(root, 0);
    }
};