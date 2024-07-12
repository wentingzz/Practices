class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int usedB = 0, usedL = 0;
        priority_queue<int, vector<int>, greater<int>> ladder; //always keep its size <= ladders
        int n = heights.size();
        for(int i = 0; i < n-1; i++){
            int diff = heights[i+1] - heights[i];
            if(diff > 0){
                if(usedL < ladders){
                    usedL++;
                    ladder.push(diff);
                }else{
                    if(!ladder.empty() and diff > ladder.top()){
                        int tmp = ladder.top();
                        ladder.push(diff);
                        ladder.pop();
                        diff = tmp;
                    }
                    if(usedB + diff > bricks) return i;
                    usedB += diff;
                    // bricks.push(diff);
                }
            }
        }
        return n-1;

    }
};
