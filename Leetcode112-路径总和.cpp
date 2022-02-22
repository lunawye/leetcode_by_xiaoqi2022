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
    bool judge(TreeNode *root, int targetSum)
    {
        if (!root)
            return false;
        else if (!root->left && !root->right && targetSum == root->val)
            return true;
        else if (!root->left && !root->right && targetSum != root->val)
            return false;
        return judge(root->left, targetSum - root->val) || judge(root->right, targetSum - root->val);
    }
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (!root)
            return false;
        return judge(root, targetSum);
    }
};