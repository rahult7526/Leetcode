/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    pair<ListNode*,ListNode*> findMiddle(ListNode *head){
        if(!head)return {NULL,head};
        
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *prev = NULL;
        
        while(fast && fast->next){
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }
        return {prev,slow};
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        //Idea is take middle as root and go recursively in left half & right half
        if(!head)return NULL;
        auto temp = findMiddle(head);
        ListNode* prev = temp.first;
        ListNode* mid = temp.second;
        TreeNode* root = new TreeNode(mid->val);
        if(prev){
            prev->next = NULL;
            root->left = sortedListToBST(head);
        }
        root->right = sortedListToBST(mid->next);
        return root;
    }
};