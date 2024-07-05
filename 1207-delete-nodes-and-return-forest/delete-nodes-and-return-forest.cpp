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
    unordered_map<int,int> del;
    TreeNode* util(TreeNode* root, queue<TreeNode*>& q){
        if(root == NULL)return NULL;
        int value = root->val;
        if(del[value]){
            if(root->left)q.push(root->left);
            if(root->right)q.push(root->right);
            return NULL;
        }
        root->left = util(root->left,q);
        root->right = util(root->right,q);
        return root;
    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> forest;
        queue<TreeNode*> q;
        del.clear();

        for(auto i: to_delete)del[i]++;
        q.push(root);

        while(!q.empty()){
            TreeNode* node = q.front(); q.pop();
            if(del[node->val]){
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            else{
                TreeNode* updated_node = util(node,q);
                forest.push_back(updated_node);
                
            }
        }

        return forest;
    }
};