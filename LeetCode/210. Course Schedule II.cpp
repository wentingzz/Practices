static const int UNVISITED = -1;
static const int VISITING = 0;
static const int VISITED = 1;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjacencyList(numCourses, vector<int>());
        vector<int> visitStatus(numCourses, UNVISITED);

        for (const vector<int>& prereq : prerequisites) {
            adjacencyList[prereq[0]].push_back(prereq[1]);
        }

        vector<int> topologicalOrder;
        for (int course = 0; course < numCourses; ++course) {
            if (hasCycle(course, adjacencyList, visitStatus, topologicalOrder)) {
                return {};
            }
        }

        return topologicalOrder;
    }

    //DFS
    bool hasCycle(int course, vector<vector<int>>& adjacencyList, vector<int>& visitStatus, vector<int>& topologicalOrder) {
        if (visitStatus[course] == VISITED) {
            return false;
        }
        if (visitStatus[course] == VISITING) {
            return true;
        }

        visitStatus[course] = VISITING;

        for (int prereq : adjacencyList[course]) {
            if (hasCycle(prereq, adjacencyList, visitStatus, topologicalOrder)) {
                return true;
            }
        }

        visitStatus[course] = VISITED;
        topologicalOrder.push_back(course);

        return false;
    }
};
