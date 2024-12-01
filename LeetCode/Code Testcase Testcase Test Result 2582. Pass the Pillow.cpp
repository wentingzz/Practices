class Solution {
public:
    int passThePillow(int n, int time) {
        time = time % (n + n - 2);
        if(time < n) return time + 1; 
        else return n - (time - n + 1);
    }
};
