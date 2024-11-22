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
    ListNode* mergeNodes(ListNode* head) {
        return rec(head->next, 0);
    }

    ListNode* rec(ListNode* head, int sum = 0){
        if(!head) return nullptr;
        if(head->val == 0){
            head->val = sum;
            head->next = rec(head->next);
            return head;
        }else return rec(head->next, sum + head->val);
    }
};
