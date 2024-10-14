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
    int limits[4] = {0, 0, 0, 0}; //lr, hr, lc, hc;
    void addNext(int& r, int& c, int& dr, int& dc, vector<vector<int>>& res, ListNode* &head){
        if(!head) return;
        if(dr == 0){ //only c changes
            for(int i = c; head && i < limits[3] && i >= limits[2]; i += dc){
                res[r][i] = head->val;
                head = head->next;
            }
            if(dc > 0){
                r++;
                c = limits[3]-1;
            }else{
                r--;
                c = limits[2];
            }
        }else{
            for(int i = r; head && i < limits[1] && i >= limits[0]; i += dr){
                res[i][c] = head->val;
                head = head->next;
            }
            if(dr > 0){
                c--;
                r = limits[1]-1;
            }else{
                c++;
                r = limits[0];
            }
        }

    }
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        limits[1] = m;
        limits[3] = n;
        vector<vector<int>> res(m, vector<int>(n, -1));
        int delta[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int changes[4][4] = {{1, 0, 0, 0}, {0, 0, 0, -1}, {0, -1, 0, 0}, {0, 0, 1, 0}}; //changes in rl, rh, cl, ch
        int i = 0, r = 0, c = 0;
        while(head){
            addNext(r, c, delta[i][0], delta[i][1], res, head);
            for(int j = 0; j < 4; j++) limits[j] += changes[i][j];
            i = (i+1) % 4;
            
        }
        return res;
    }
};
