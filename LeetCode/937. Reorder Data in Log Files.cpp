class Solution {
public:
    bool parseLog(string& log, vector<string>& res){
        int i = 0, n = log.size();
        string cur = ""; 
        while(log[i] != ' ') cur += log[i++];
        res.push_back(cur);
        while(i < n){
            if(log[i] >= 'a' and log[i] <= 'z'){
                res.push_back(log.substr(cur.size()));
                return false;
            }
            i++;
        }
        return true;
    }
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<vector<string>> let;
        vector<string> dig;
        int n = logs.size();
        for(string& log: logs){
            vector<string> content;
            if(parseLog(log, content)) dig.push_back(log);
            else let.push_back(content);
            
        }
        sort(let.begin(), let.end(), [](const vector<string>& l1, const vector<string>& l2){
            if(l1[1] == l2[1]) return l1[0] < l2[0];
            return l1[1] < l2[1];
        });
        vector<string> res;
        for(auto& l: let) res.push_back(l[0] + l[1]);
        for(string& l: dig) res.push_back(l);
        return res;
    }
};
