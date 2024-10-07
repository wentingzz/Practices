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
struct CompareListNode{
    bool operator()(ListNode* l1, ListNode* l2){
        if(l1 and l2) return l1->val > l2->val;
        if(l1) return true;
        return false;
    }
};
class TimeSolution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, CompareListNode> pq;
        for(ListNode* l: lists){
            if(l) pq.push(l);
        }
        ListNode * res = new ListNode(0), *cur = res;
        
        while(!pq.empty()){
            cur->next = pq.top(); pq.pop();
            cur = cur->next;
            if(cur->next) pq.push(cur->next);
        }
        return res->next;
    }
};


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
class SpaceSolution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n == 0) return nullptr;
        for(int i = 1; i < n; i++){
            lists[0] = mergeTwo(lists[0], lists[i]);
        }
        return lists[0];
    }

    ListNode* mergeTwo(ListNode* l1, ListNode* l2){
        if(l1 and l2){
            if(l1->val < l2->val){
                l1->next = mergeTwo(l1->next, l2);
                return l1;
            }
            l2->next = mergeTwo(l1, l2->next);
            return l2;
        }
        if(l1) return l1;
        return l2;
    }
};
