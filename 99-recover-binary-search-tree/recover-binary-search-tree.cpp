class Solution {
public:
    void inorder (TreeNode* root, TreeNode* &prev, TreeNode* &x, TreeNode* &y) {
        if (!root) return ;

        inorder(root->left, prev, x, y);
        if (prev && root->val < prev->val) {
            if (!x) {
                x = prev;
                y = root;
            }
            else {
                y = root;
                return;
            }
        }
        prev = root;
        inorder(root->right, prev, x, y);
    }
    void recoverTree(TreeNode* root) {
        TreeNode *prev = nullptr, *x = nullptr, *y = nullptr;
        inorder (root, prev, x, y);
        swap(x->val , y->val);
    }
};