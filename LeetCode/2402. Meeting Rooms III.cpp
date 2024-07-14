class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        }); //sort by start time

        priority_queue<long long, vector<long long>, greater<long long>> rooms; //empty rooms
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> used; //used rooms
        for(int i = 0; i < n; i++) rooms.push(i);
        vector<int> res(n, 0); //all rooms are used 0 times initially

        for(vector<int>& m: meetings){
            while(!used.empty() and used.top().first <= m[0]){ //it ends before this meeting starts
                rooms.push(used.top().second); //make it avialble
                used.pop();
            }
            if(rooms.empty()){
                //no empty room, delay the meeting
                used.push({m[1] + used.top().first - m[0], used.top().second});
                res[used.top().second]++;
                // cout << "Use room(d) " << used.top().second << " (" << used.top().first << " - " << (m[1] + used.top().first - m[0]) << ") " << endl;
                used.pop();
            }else{
                used.push({m[1], rooms.top()}); //no delay
                res[rooms.top()]++;
                // cout << "Use room " << rooms.top() << " (" << m[0] << " - " << m[1] << ") " <<  endl;
                rooms.pop();
            }
        }
        
        int maxUsed = 0;
        for(int i = 1; i < n; i++){
            if(res[i] > res[maxUsed]) maxUsed = i;
        }

        return maxUsed;
    }
};
