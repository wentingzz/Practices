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
    int gcd(int a, int b){
        return b == 0 ? a : gcd(b, a % b);
    }

    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* cur = head, * nxt = head->next;

        while(cur and nxt){
            cur->next = new ListNode(gcd(cur->val, nxt->val), nxt);
            cur = cur->next->next;
            nxt = nxt->next;
        }
        return head;
    }
};
