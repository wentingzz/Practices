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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        bitset<100001> seen;
        for(int& n: nums) seen[n] = 1;
        while(head and seen[head->val] == 1){
            head = head->next;
        }
        ListNode* cur = head;
        while(cur){
            while(cur->next and seen[cur->next->val] == 1) cur->next = cur->next->next;
            cur = cur->next;
        }
        return head;
    }
};
