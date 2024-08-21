class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        vector<string> matrix;
        int n = encodedText.size();
        int cols = n / rows;
        for(int i = 0; i < n; i += cols){
            matrix.push_back(encodedText.substr(i, cols));
        }
        string res = "";
        for(int i = 0; i < cols; i++){
            for(int j = 0; j < rows && j + i < cols; j++){
                res += matrix[j][j+i];
            }
        }

        res.erase(res.find_last_not_of(' ') + 1);
        return res;
    }
};


class SpaceBetterSolution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int cols = encodedText.size() / rows;
        string res = "";
        for(int i = 0; i < cols; i++){
            for(int j = 0; j < rows && j + i < cols; j++){
                res += encodedText[j*cols + j + i];
            }
        }

        res.erase(res.find_last_not_of(' ') + 1);
        return res;
    }
};
