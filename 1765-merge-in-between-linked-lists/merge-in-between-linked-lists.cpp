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
class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        
        
        ListNode *temp1 = list1;
        ListNode *prev = list1;
        ListNode *temp2 = list1;
        ListNode *tail = list2;

        int index = 0;
        while(temp1 != 0 and index < a)
        {
            prev = temp1;
            temp1 = temp1->next;
            index++;
        }

        index = 0;
        while(temp2 != 0 and index < b)
        {
            temp2 = temp2->next;
            index++;
        }

        while(tail != 0 and tail->next != 0) 
        tail = tail->next;

        cout << prev->val << " " << temp2->val << endl;

        prev->next = list2;
        tail->next = temp2->next;

        return list1;
        
    }
};