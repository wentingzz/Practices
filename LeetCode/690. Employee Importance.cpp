/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class BestSolution {
public:
    unordered_map<int, Employee*> m;

    int getImportance(vector<Employee*> employees, int id) {
        for(Employee* e: employees){
            m[e->id] = e;
        }

        return getImportance(m[id]);
    }

    int getImportance(Employee* e){
        int res = e->importance;
        for(int& sub: e->subordinates){
            res += getImportance(m[sub]);
        }
        return res;
    }
};

/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> id2e;
        for(int i = 0; i < employees.size(); i++) id2e[employees[i]->id] = employees[i];

        int res = 0;
        queue<Employee*> q;
        q.push(id2e[id]);
        while(!q.empty()){
            Employee* e = q.front(); q.pop();
            res += e->importance;
            for(int& sub: e->subordinates) q.push(id2e[sub]);
        }
        return res;
    }
};
