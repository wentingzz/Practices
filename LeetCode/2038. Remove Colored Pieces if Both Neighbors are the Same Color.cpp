class QuickerSolution {
public:
    bool winnerOfGame(string colors) {
        int aCount = 0, bCount = 0;
        int count = 1;  // Start from 1 as we start comparing from the second character
        
        for (int i = 1; i < colors.size(); ++i) {
            if (colors[i] == colors[i - 1]) {
                count++;
            } else {
                if (colors[i - 1] == 'A' && count >= 3) {
                    aCount += count - 2;
                } else if (colors[i - 1] == 'B' && count >= 3) {
                    bCount += count - 2;
                }
                count = 1;  // Reset count for the new color
            }
        }
        
        // Handle the last sequence
        if (colors.back() == 'A' && count >= 3) {
            aCount += count - 2;
        } else if (colors.back() == 'B' && count >= 3) {
            bCount += count - 2;
        }
        
        return aCount > bCount;
    }
};

class Solution {
public:
    bool winnerOfGame(string colors) {
        int counts[2] = {0, 0};
        int count = 0;
        char cur = colors[0];
        for(char& c: colors){
            if(c != cur){
                counts[cur - 'A'] += max(0, count - 2);
                count = 1;
                cur = c;
            }else{
                count++;
            }
        }
        counts[cur - 'A'] += max(0, count - 2);
        return counts[0] > counts[1];
    }
};
