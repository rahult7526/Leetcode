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
    void helper(TreeNode* root,string temp,string&ans)
    {
        if(root==NULL)
        {
            return;
        }
        if(root->left == NULL && root->right == NULL)
        {
            temp = char(97+root->val) + temp;
            if(temp<ans)
            {
                ans =temp;
            }
            return ;
        }
        char t = char(97+root->val);
        helper(root->left,t + temp,ans);
        helper(root->right,t + temp,ans);


    }
    string smallestFromLeaf(TreeNode* root) {
        string ans=string(8501,'z');
        string temp="";
        helper(root,temp,ans);
        return ans;
    }
};