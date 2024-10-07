class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> pres(numCourses);
        for(vector<int>& p: prerequisites){
            pres[p[0]].push_back(p[1]);
        }

        vector<bool> taken(numCourses, false);
        vector<bool> taking(numCourses, false);

        for(int i = 0; i < numCourses; i++){
            if(!dfs(pres, i, taken, taking)) return false;
        }
        return true;
    }

    bool dfs(vector<vector<int>>& pres, int cur, vector<bool>& taken, vector<bool>& taking){
        if(taken[cur]) return true;
        if(taking[cur]) return false;

        taking[cur] = true;
        for(int& pre: pres[cur]){
            if(!dfs(pres, pre, taken, taking)) return false;
        }
        taking[cur] = false;
        return taken[cur] = true;
    }
};
