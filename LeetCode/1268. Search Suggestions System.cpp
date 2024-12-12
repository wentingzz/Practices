class SimilarSolution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        vector<vector<string>> res;
        int j = 0, n = products.size(), m = searchWord.size();
        string cur = "";
        for(int i = 0; i < m; i++){
            cur += searchWord[i];
            auto it = lower_bound(products.begin() + j, products.end(), cur);
            j = distance(it, products.begin());
            vector<string> list;
            for(int i = 0; i < 3; i++){
                if(it == products.end() or it->substr(0, cur.size()) != cur) break;
                list.push_back(*it);
                it++;
            }
            res.push_back(list);
        }
        return res;
    }

};

class Solution {
public:
    void addThree(vector<string>& products, string& match, int start, vector<vector<string>>& res){
        vector<string> cur;
        for(int i = start; i < start + 3 && i < products.size(); i++){
            if(products[i].substr(0, match.size()) != match) break;
            cur.push_back(products[i]);
        }
        res.push_back(cur);
    }
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        vector<vector<string>> res;
        int j = 0, n = products.size(), m = searchWord.size();
        string cur = "";
        for(int i = 0; i < m; i++){
            cur += searchWord[i];
            while(j < n){
                if(cur == products[j].substr(0, i+1)) break;
                j++;
            }
            addThree(products, cur, j, res);
        }
        return res;
    }

};
