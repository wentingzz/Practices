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
    vector<int> res = {INT_MAX, 0};
    bool isCritical(int prev, int cur, int next){
        if(prev < cur and next < cur) return true;
        if(prev > cur and next > cur) return true;
        return false;
    }
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int i = 0, prev = head->val, last = -1;
        ListNode* cur = head->next;
        while(cur->next){
            if(isCritical(prev, cur->val, cur->next->val)){
                if(last > -1){
                    res[0] = min(res[0], i - last);
                    res[1] = res[1] + i - last;
                }
                last = i;
            }
            //increment
            prev = cur->val;
            cur = cur->next;
            i++;
        }
        if(res[0] == INT_MAX) return {-1, -1};
        return res;
    }
};
