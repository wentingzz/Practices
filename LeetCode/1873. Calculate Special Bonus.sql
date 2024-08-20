# Write your MySQL query statement below
SELECT e.employee_id, IF(e.employee_id % 2 = 1 AND e.name NOT LIKE 'M%', e.salary, 0) as 'bonus'
FROM Employees e
ORDER BY e.employee_id
