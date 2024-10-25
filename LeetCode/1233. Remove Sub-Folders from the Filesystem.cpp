
class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        //sub folder's path must be longer than folder's path
        sort(folder.begin(), folder.end(), [](const string& s1, const string& s2){
            if(s1.size() == s2.size()) return s1 < s2;
            return s1.size() < s2.size();
        });
        
        vector<string> res;
        for(string& f: folder){
            if(isSubFolder(f, res)) continue;
            res.push_back(f);
        }
        return res;
    }

    bool isSubFolder(string& f, vector<string>& seen){
        string cur = "";
        for(char&c: f){
            if(c == '/'){
                if(find(seen.begin(), seen.end(), cur) != seen.end()) return true;
            }
            cur += c;
        }
        return false;
    }
};
