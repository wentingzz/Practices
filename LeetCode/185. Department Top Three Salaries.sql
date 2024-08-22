
SELECT t.dname as 'Department', t.name as 'Employee', t.salary as 'Salary' 
FROM (
    SELECT e.name, e.salary, d.name as 'dname', DENSE_RANK() OVER (PARTITION BY d.id ORDER BY e.salary DESC) as 'rank'
    FROM employee e
    LEFT JOIN department d ON e.departmentId = d.id
) t
WHERE t.rank <= 3
