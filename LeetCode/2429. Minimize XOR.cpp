class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int count = 0;
        while(num2){
            if(num2 & 1) count++;
            num2 >>= 1;
        }

        int res = 0;
        for (int i = 31; i >= 0 && count > 0; i--) {
            if (num1 & (1 << i)) { 
                res |= (1 << i);
                count--;
            }
        }
        for (int i = 0; i < 32 && count > 0; i++) {
            if (!(res & (1 << i))) {
                res |= (1 << i);
                count--;
            }
        }
        
        return res;
    }
};
