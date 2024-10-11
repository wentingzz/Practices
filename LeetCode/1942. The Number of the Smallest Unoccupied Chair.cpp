class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int arrival = times[targetFriend][0];
        //we want to know what seat they take for the friends before arrivel time of targetFriend
        sort(times.begin(), times.end());
        //empty seats that have been used before and now are empty for the next friend
        priority_queue<int, vector<int>, greater<int>> chairs;
        //leave time, seat number
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> friends;
        int size = 0;
        for(auto& it: times){
            // pop all friends that leave before this friend
            while(!friends.empty() and friends.top().first <= it[0]){
                chairs.push(friends.top().second);
                friends.pop();
            }
            if(it[0] >= arrival) break;
            if(chairs.empty()){
                friends.push({it[1], size++}); //grab a new chair
            } else {
                friends.push({it[1], chairs.top()});
                chairs.pop();
            }
        }
        return (chairs.empty() ? size : chairs.top());
    }
};
