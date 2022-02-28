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
    bool judge(TreeNode *root, TreeNode *B)
    {
        if (!B)
            return true;
        if (!root || root->val != B->val)
            return false;                                                  //主根没跑完或者数值不相等就返回false
        return judge(root->left, B->left) && judge(root->right, B->right); //写成root==B判断不出来，因为可能一边子树不同
    }
    bool isSubStructure(TreeNode *A, TreeNode *B)
    {
        if (!B || !A)
            return false;
        return judge(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }
};
