/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:

    void preOrder(TreeNode* root, TreeNode* &ref, TreeNode* target){
        if(root == NULL)
            return;

        if(root->val == target->val)
            ref = root;

        preOrder(root->left,ref,target);
        preOrder(root->right,ref,target);
    }

    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        TreeNode* ref = NULL;
        preOrder(cloned,ref,target);
        return ref;
    }
};