class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q)    return true;  // if one ends early then other, then this subtree not balanced here
        if(!p || !q)    return false; // both ends together, the subtree is still same

        // if value of current nodes not same, current subtree not same, no need to check left and right subtree and straighaway return false (trees not same)
        return p->val==q->val 
                    && isSameTree(p->left, q->left) 
                    && isSameTree(p->right, q->right);
    }
};
