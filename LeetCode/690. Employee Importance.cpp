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
