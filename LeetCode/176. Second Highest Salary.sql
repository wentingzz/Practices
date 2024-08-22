/* Write your T-SQL query statement below */
SELECT 
    CASE 
        WHEN COUNT(*) > 0 THEN MAX(t.salary) 
        ELSE NULL 
    END as 'SecondHighestSalary'
FROM (
    SELECT p.salary, 
        ROW_NUMBER() OVER (ORDER BY p.salary DESC) as 'rank'
    FROM (
        SELECT DISTINCT e.salary 
        FROM Employee e
    ) p
) t
WHERE t.rank = 2
