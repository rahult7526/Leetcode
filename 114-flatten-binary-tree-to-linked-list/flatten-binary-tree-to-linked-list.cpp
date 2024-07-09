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
    void attachatright(TreeNode* root,TreeNode* temp){
    while(root->right!=nullptr)root=root->right;
    root->right=temp;
}

void preorderflatten(TreeNode* root){
    if (!root)return; 
    
    preorderflatten(root->left);
    preorderflatten(root->right);
    TreeNode* temp=root->right;
    if(root->left){
    root->right=root->left;attachatright(root->right,temp);
    }root->left=nullptr;

    }

void flatten(TreeNode* root) {
      
    preorderflatten(root);
    
    }
};