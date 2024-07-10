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
class Solution {
    void __longestZigZag(TreeNode *root, int cost, int &ans, bool direction)
    {
        if(root == nullptr)
            return;
        ans = max(cost, ans);
        if(direction == true)
        {
            __longestZigZag(root->left, cost + 1, ans, false);
            __longestZigZag(root->right, 0, ans, true);
        }
        else
        {
            __longestZigZag(root->right, cost + 1, ans, true);
            __longestZigZag(root->left, 0, ans, false);
        }
        return;
    }


public:
    int longestZigZag(TreeNode* root) {
        int ans = 0;
        __longestZigZag(root->left, 0, ans, false);
        __longestZigZag(root->right, 0, ans, true);
        if(root->left == root->right)
            return 0;
        return ans + 1;
    }
};