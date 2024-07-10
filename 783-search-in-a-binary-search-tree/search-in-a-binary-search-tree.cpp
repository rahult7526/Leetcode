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
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        // base case 
        // if element not found or if element found 
        if (root == NULL)
        {
            return NULL ; 
        }

        if (root -> val == val)
        {
            return root ; 
        }

        // return statments mandatory in recursion because return type non NULL here
        // left part traverse
        if (root -> val > val)
        {
            return searchBST(root -> left, val) ;
        }

        // right part traverse 
        else    
        {
            return searchBST(root -> right, val) ; 
        }
    }
};