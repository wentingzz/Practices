/* Better Solution */
WITH unbanned AS (
    SELECT * FROM users u
    WHERE u.banned = 'NO'
)

SELECT t.request_at as 'Day', ROUND(1.0 * SUM(IIF(t.status = 'completed', 0, 1)) / COUNT(*), 2) as 'Cancellation Rate'
FROM trips t
INNER JOIN unbanned dr ON t.driver_id = dr.users_id
INNER JOIN unbanned cl ON t.client_id = cl.users_id
WHERE t.request_at BETWEEN '2013-10-01' AND '2013-10-03'
GROUP BY t.request_at


/* Slower Solution */
WITH unbanned AS (
    SELECT * FROM users u
    WHERE u.banned = 'NO'
)

SELECT t.request_at as 'Day', ROUND(1.0 * SUM(IIF(t.status = 'completed', 0, 1)) / COUNT(*), 2) as 'Cancellation Rate'
FROM trips t
JOIN unbanned dr ON t.driver_id = dr.users_id
JOIN unbanned cl ON t.client_id = cl.users_id
WHERE t.request_at BETWEEN '2013-10-01' AND '2013-10-03'
GROUP BY t.request_at
