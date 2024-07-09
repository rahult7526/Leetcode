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
    void traverse(TreeNode* root,bool &ans,TreeNode* &prev){
        if(!root) return;

        traverse(root->left,ans,prev);

        if(!prev){
            prev = root;
        }
        else{

            if(prev->val >= root->val){
                ans = false;
                return;
            }

            else{
                prev = root;
            }


        }
        traverse(root->right,ans,prev);

    }

    bool isValidBST(TreeNode* root) {
        
        bool ans = true;
        TreeNode* prev = NULL;

        traverse(root,ans,prev);

        return ans;
        

    }
};