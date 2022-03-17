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
    bool dfs(TreeNode *rootA, TreeNode *rootB)
    {
        if (!rootA && !rootB)
            return true;
        if (!rootA || !rootB || rootA->val != rootB->val)
            return false;
        return dfs(rootA->left, rootB->right) && dfs(rootA->right, rootB->left);
    }
    bool isSymmetric(TreeNode *root)
    {
        if (!root)
            return false;
        return dfs(root, root);
    }
};