/* Write your T-SQL query statement below */
SELECT u.name, ISNULL(SUM(r.distance), 0) as 'travelled_distance'
FROM users u
LEFT JOIN rides r ON u.id = r.user_id
GROUP BY u.id, u.name
ORDER BY 2 DESC, 1 ASC
