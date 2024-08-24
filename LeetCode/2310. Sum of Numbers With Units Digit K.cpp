class Solution {
public:
    
    int minimumNumbers(int num, int k) {
        if(num == 0) return 0;
        int unit = (num % 10);
        for(int i = 1; i <= 10; i++){
            if(k * i <= num and (k * i) % 10 == unit){
                return i;
            }
        }
        return -1;
    }
};
